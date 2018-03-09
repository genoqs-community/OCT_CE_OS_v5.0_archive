//
// Copyright (C) 2004, 2005, 2006, 2007 genoQs Machines
// This file is part of Octopus_OS - 
// the firmware of the genoQs Machines Octopus, MIDI Control Sequencer
//
// The source code Octopus_OS is available for use in accordance with the 
// GNU General Public License (GPL). For more information about Open Source 
// licensing, please visit http://www.opensource.org/
//
// Octopus_OS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Octopus_OS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Octopus_OS; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//



// Key execution snippet for the Octave circle. May be reused


	// If the key is in the Octave circle:
	if ( 	(keyNdx == KEY_NOTE_C	)
	 	|| 	(keyNdx == KEY_NOTE_Cup	)
		||	(keyNdx == KEY_NOTE_Cis	)
		||	(keyNdx == KEY_NOTE_D	)
		||	(keyNdx == KEY_NOTE_Dis	)
		||	(keyNdx == KEY_NOTE_E	)
		||	(keyNdx == KEY_NOTE_F	)
		||	(keyNdx == KEY_NOTE_Fis	)
		||	(keyNdx == KEY_NOTE_G	)
		||	(keyNdx == KEY_NOTE_Gis	)
		||	(keyNdx == KEY_NOTE_A	)
		||	(keyNdx == KEY_NOTE_Ais	)
		||	(keyNdx == KEY_NOTE_B	)
		){

		// Do this for all tracks in the selection
		for ( row=0; row < MATRIX_NROF_ROWS; row++ ){
			
			// If track is not selected, continue
			if ( (target_page->trackSelection & (1<<row) ) == 0 ){
	
				continue;
			}
			
			// Transposing multiple tracks at the same time 
			// not working yet due to mess when multiple keys are pressed.
			if ( my_bit_cardinality( target_page->trackSelection ) > 1 ){
				break;
			}

			// Kill the event offset
			target_page->Track[row]->event_offset[ATTR_PITCH] = 0;
	
			// Establish the offset depending on the pressed octave key
			switch( keyNdx ){
	
				case KEY_NOTE_C:		j = 0;		break;
				case KEY_NOTE_Cis:		j = 1;		break;
				case KEY_NOTE_D:		j = 2;		break;
				case KEY_NOTE_Dis:		j = 3;		break;
				case KEY_NOTE_E:		j = 4;		break;
				case KEY_NOTE_F:		j = 5;		break;
				case KEY_NOTE_Fis:		j = 6;		break;
				case KEY_NOTE_G:		j = 7;		break;
				case KEY_NOTE_Gis:		j = 8;		break;
				case KEY_NOTE_A:		j = 9;		break;
				case KEY_NOTE_Ais:		j = 10;		break;
				case KEY_NOTE_B:		j = 11;		break;
				case KEY_NOTE_Cup:		j = 12; 	break;
			}
	

			switch( j ){

				case 0:
					// If the pitch is a C already, transpose octave down
					if (( target_page->Track[row]->attr_PIT % 12 ) == 0 ){

						// Make sure we stay within bounds
						if ( target_page->Track[row]->attr_PIT >= (TRACK_MIN_PITCH+12) ){ 
							
							// Go down one octave
							target_page->Track[row]->attr_PIT -= 12;
						}
					}
					else{
						// The general case of pitch selection
						target_page->Track[row]->attr_PIT =
							( target_page->Track[row]->attr_PIT / 12 )*12 + j;
					}

					break;

				case 12:
					// This means Cup was pressed
					// Transpose up by an octave if enough "headroom"
					if ( target_page->Track[row]->attr_PIT 
										<= (TRACK_MAX_PITCH-12) 
						){
											
						target_page->Track[row]->attr_PIT += 12;
					}
					break;
	
				default:
					// The general case of pitch selection
					target_page->Track[row]->attr_PIT =
						( target_page->Track[row]->attr_PIT / 12 )*12 + j;
					break;

			} // switch( j );

		}// Row iterator

	} // Key is in the octave circle




