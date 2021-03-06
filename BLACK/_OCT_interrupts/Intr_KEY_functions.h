

// Checks whether there is a key pressed in the given range [min..max], and
// ..returns either the first key found in the range, or FALSE if no key is pressed.
// This should be a linear time operation.
unsigned int is_pressed_keyrange( unsigned int min, unsigned int max ){

	unsigned int result = FALSE;
	unsigned int i = 0;

	// No key is pressed to begin with
	if ( key_pressed == 0 ){

		result = FALSE;
	}
	else {
		
		// Linear scan through the buttons in question: Selectors and Steps.
		for( i=min; i <= max; i++ ){
		
			// There is a key pressed - in the Step Range
			if (	( pressed_keys[i] >= min ) 
				&&	( pressed_keys[i] <= max ) 
				){
				
				// Store the result
				result = pressed_keys[i];
				
				// Return on the first found pressed_key - performance reasons.
				break;
			} // key pressed in given step range
		} // button iterator
	} // some key is pressed in matrix
	
	// Should contain the wanted result.
	return result;
}


// Checks whether there is a key pressed in the row zero range, and
// ..returns either the first key found in the range, or 0 if no relevant key is pressed.
// Linear time operation
unsigned int is_pressed_rowzero(){
	
	unsigned int result = 0;
	unsigned int i = 0;
	unsigned int min = 20;
	unsigned int max = 185;

	// No key is pressed to begin with
	if ( key_pressed == 0 ){

		result = 0;
	} // No key is pressed

	// Some key is pressed
	else{

		// Linear scan through the buttons in question: Rowzero buttons.
		for( i=min; i <= max; i+=11 ){
		
			// There is a key pressed - in the Step Range
			if (	( pressed_keys[i] >= min ) 
				&&	( pressed_keys[i] <= max ) 
				){

				result = (i - 9) / 11;
				break;
			} // Pressed key in range
		} // Key iterator

	} // some key is pressed

	return result;
}



// Checks whether there is a key pressed in the page range, and
// ..returns either the first key found in the range, or 0 if no page key is pressed.
// Linear time operation
unsigned int is_pressed_pagerange(){

	unsigned int result = 0;
	unsigned int i = 0;
	unsigned int min = 11;
	unsigned int max = 185;
	unsigned char temp = FALSE;

	// No key is pressed to begin with
	if ( key_pressed == 0 ){

		result = 0;
	}
	else {
		
		// Linear scan through the buttons in question: Selectors and Steps.
		for( i=min; i <= max; i++ ){
		
			// There is a key pressed - in the Step Range
			if (	( pressed_keys[i] >= min ) 
				&&	( pressed_keys[i] <= max ) 
				){
				
				// Store the result
				result = pressed_keys[i];

				// Eliminate the keypresses that are not pages
				switch( pressed_keys[i] ){

					// These keys don't belong to the page set, are just in the range.
					case 0:

					// Row zero
					case 20:	case 31:	case 42:	case 53:
					case 64:	case 75:	case 86:	case 97:
					case 108:	case 119:	case 130:	case 141:
					case 152:	case 163:	case 174:	case 185:

					// Bottom row
					case 21: 	case 32: 	case 43: 	case 54: 
					case 65: 	case 76:	case 87:  	case 164: 	
					case 175:
						
					// CCMAP keys
					case 98: 	case 109: 	case 120: 	case 131: 	
					case 142:	case 153:

						// Key is not interesting, nothing to do
						result = FALSE;
						break;

					default:
	
						// Signal that a valid page button was found
						temp = TRUE;
						break;
				}
				
				// Return on the first found pressed_key - performance reasons.
				if ( temp == TRUE ){
					break;
				}

			} // key pressed in given step range

		} // button iterator
	} // some key is pressed in matrix
	
	//d_iag_printf( "is_pressed_pagerange():%d\n", result );
	// Should contain the wanted result.
	return result;
}



// Boolean - whether the gridtrack border is pressed or not
unsigned char is_pressed_gridtrack_border(){

	unsigned int result = FALSE;
	unsigned int i = 0;

	unsigned int minL = 11;
	unsigned int maxL = 42;
	
	unsigned int minR = 154;
	unsigned int maxR =	185;

	unsigned char temp = FALSE;

	// No key is pressed to begin with
	if ( key_pressed == 0 ){

		result = FALSE;
	}

	// LHS
	// Linear scan through the buttons in question: Selectors and Steps.
	for( i=minL; i <= maxL; i++ ){
	
		// There is a key pressed - in the Step Range
		if (	( pressed_keys[i] >= minL ) 
			&&	( pressed_keys[i] <= maxL ) 
			){
			
			// Store the result
			result = pressed_keys[i];

			// Eliminate the keypresses that are not pages
			switch( pressed_keys[i] ){

				// These keys don't belong to the page set, are just in the range.
				case 0:

				// Row zero
				case 20:	case 31:	case 42:	case 53:
				case 64:	case 75:	case 86:	case 97:
				case 108:	case 119:	case 130:	case 141:
				case 152:	case 163:	case 174:	case 185:

				// Bottom row
				case 21: 	case 32: 	case 43: 	case 54: 
				case 65: 	case 76:	case 87:  	case 164: 	
				case 175:
					
				// CCMAP keys
				case 98: 	case 109: 	case 120: 	case 131: 	
				case 142:	case 153:

					// Key is not interesting, nothing to do
					result = FALSE;
					break;

				default:

					// Signal that a valid page button was found
					temp = TRUE;
					break;
			}
			
			// Return on the first found pressed_key - performance reasons.
			if ( temp == TRUE ){
				break;
			}
		} // key pressed in given step range
	} // button iterator
	
	if ( result != FALSE ){
		return TRUE;
	}



	// RHS
	// Linear scan through the buttons in question: Selectors and Steps.
	for( i=minR; i <= maxR; i++ ){
	
		// There is a key pressed - in the Step Range
		if (	( pressed_keys[i] >= minR ) 
			&&	( pressed_keys[i] <= maxR ) 
			){
			
			// Store the result
			result = pressed_keys[i];

			// Eliminate the keypresses that are not pages
			switch( pressed_keys[i] ){

				// These keys don't belong to the page set, are just in the range.
				case 0:

				// Row zero
				case 20:	case 31:	case 42:	case 53:
				case 64:	case 75:	case 86:	case 97:
				case 108:	case 119:	case 130:	case 141:
				case 152:	case 163:	case 174:	case 185:

				// Bottom row
				case 21: 	case 32: 	case 43: 	case 54: 
				case 65: 	case 76:	case 87:  	case 164: 	
				case 175:
					
				// CCMAP keys
				case 98: 	case 109: 	case 120: 	case 131: 	
				case 142:	case 153:

					// Key is not interesting, nothing to do
					result = FALSE;
					break;

				default:

					// Signal that a valid page button was found
					temp = TRUE;
					break;
			}
			
			// Return on the first found pressed_key - performance reasons.
			if ( temp == TRUE ){
				break;
			}
		} // key pressed in given step range
	} // button iterator


	// Result is now a number, make it boolean
	if ( result != FALSE ){
		result = TRUE;
	}

	//d_iag_printf( "is_pressed_borderrange():%d\n", result );
	// Should contain the wanted result.
	return result;
}




// Returns TRUE if the target_key is pressed, FALSE otherwise
unsigned char is_pressed_key( unsigned int target_key ){
	
	unsigned int i = 0;
	unsigned char result = FALSE;
	
	// Iterate through all buttons
	for( i=1; i <= 258; i++ ){
	
		// There is a key pressed - in the Step Range
		if (	( pressed_keys[i] == target_key ) 
			){

			result = TRUE;			
			break;
		} // key pressed in given step range
	} // button iterator

	return result;
}



// Returns the row of a given step key index - beware: mind  bending logic in HW
unsigned int row_of (unsigned int stepKeyNdx) {
	return ( stepKeyNdx - (((stepKeyNdx / 11) * 11) ) );
}

// Returns the column of a given step key index : mind bending logic in HW
unsigned int column_of (unsigned int stepKeyNdx) {
	return (stepKeyNdx / 11) - 1;
}

// Returns the index of the (first) selected track in selection
unsigned int ndx_of( unsigned int trackSelection ){
	unsigned int i=0;
	for (i=0; i<MATRIX_NROF_ROWS; i++) {

		if ((VIEWER_page->trackSelection ^ (1<<i)) == 0) {

			return i;
		}
	}
	return 0;
}








// Computes the key index given the reg(ister), the significant byte xSB and the port value
unsigned int computeKeyNdx (	unsigned char reg, 
								unsigned char xSB, 
								unsigned char portValue) {

	
	unsigned int i=0, row=0, ndx=0;

	// Prevent generating wrong keyNdx values and wasting time.
	if ( portValue == 0 ){
		return 0;
	}

	// Compute the Row by shifting until the bit is found. 6 is a hardware given number.
	// Loop is intentionally left to be of worst case size for runtime stability.
	for (i=0; i<6; i++) {
		// Shift a one until the pressed bit is found
		if (portValue & (1<<i)) {
			row=i;
		}
	}

	// xSB is either 0 or 5 and can be used as an offset for row computation	
	// Compute the real row
	row = row + xSB;

	// Now implement the Key Index sheet
	switch (reg) {
		// This is the first column
		case 0:
			ndx = row;
			break;
			
		// These are the MATRIX columns
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
			ndx = 10 + ((reg-1) * 11) + row;
			break;

		case 18:
			ndx = 196 + row;
			break;
		
		// 196 is the last Matrix index
		case 19:
			ndx = 205 + row;
			break;

		// 205 is the last reg19 index
		case 20:
			ndx = 214 + row;
			break;

		// 214 is the last reg20 index
		case 21:
			ndx = 223 + row;
			break;
		
		//...
		case 22:
			ndx = 232 + row;
			break;
		
		//...
		case 23:
			ndx = 241 + row;
			break;
		
		//...
		case 24:
			ndx = 250 + row;
			break;

	} // end of switch
	
	return (ndx+1);
}


// init the MIR fields to all 0;
void initMIR() {
	
//	unsigned char side, ndx, color;
//	
//	for (side = 0; side < 2; side++) {
//		for (ndx = 0; ndx < 18; ndx++) {
//			for (color = 0; color < 3; color++) {
//				MIR[side][ndx][color] = 0;
//			}
//		}
//	}

	// unsigned char MIR [2][17][3];
	// 204 = 2 x 17 x 3
	memset( MIR, 0, 204);

}



// Checks the port to see whether there is a key pressed. Boolean return.
// has to be called from within scanKeys().
unsigned char is_key_active(){

	unsigned int LSB_bus 	= 0;
	unsigned int MSB_bus 	= 0;
	unsigned int my_port 	= 0;
	unsigned int wait 		= 15;
	unsigned char result 	= FALSE;

	// Select and read the LSB Key_Bus
	HAL_WRITE_UINT32( E7T_IOPDATA, 		SELECT_KEY_LSB_DEVICE 	
									| 	IMPULSE_HIGH 	
									| 	CLOCK_KEY_LOW 
									| 	OCTDEF_UART2_MODE );
	// Marcel's wait loop
	my_wait(wait);

	// Read the port and remember the LSB bus content
	HAL_READ_UINT32( E7T_IOPDATA, my_port );
	LSB_bus = my_port  &  0xff;
	
	// Read the MSB Key_Bus
	HAL_WRITE_UINT32( E7T_IOPDATA , 	SELECT_KEY_MSB_DEVICE 
									| 	IMPULSE_LOW 
									| 	CLOCK_KEY_LOW 
									| 	OCTDEF_UART2_MODE );

	// Marcel's wait loop
	my_wait(wait);

	// Read the port and remember the MSB bus content
	HAL_READ_UINT32(E7T_IOPDATA, my_port);
	MSB_bus = my_port  &  0xff;
		
	// This is where key_pressed may turn false.
	if (( LSB_bus | MSB_bus ) != 0 ){

		result = TRUE;
	}
	else{

		result = FALSE;
	}

	return result;
}






