


// FLASH DEFINE - Handle with great care!! - Used in the flash routines
#define 	MY_FLASH_BASE			0x01900000		// This should be 0x01900000
#define		MY_EXECUTABLE_BASE		0x01820000		// This should be 0x01820000
#define		MY_CONFIGFILE_BASE		0x019F0000		// This is 0x019F0000, by RedBoot default

#define		DEFAULT 				0
#define		UPLOAD_IN_PROGRESS		1
#define 	UPLOAD_COMPLETE			2


// UART set to MIDI baud rate as calculated offline.
#define 	MIDIBAUDCOUNTER		49 << 4

// Indicates granularity of STEP grid, influences intr frequency
#define 	CLOCK_FREQUENCY		50000000

// MAX accelleration rate of the timer interrupt, reduced accordingly in the pages
#define 	OCTDEF_MAX_TEMPO_MULTIPLIER		4

// This is defined in the MIDI protocol and should not be changed !!
#define 	OCTDEF_MIDI_TICKS_PER_QUARTERNOTE	24


// MASTER resolution of Octopus! (PPQN = 4x)
#define		OCTDEF_TTC_PER_16TH					12

// Defines the ticks between 16ths at 4xT speed of the timer
#define 	OCTDEF_TIMER_TICKS_PER_16TH_AT4X		3

// Used to set the alarm for the TV Scanner (key interpreter from hardware)
#define 	TV_FREQUENCY			2		// initially 1, but with  3 scan cycles


// UART2 MODE SWITCH BETWEEN USB AND MIDI. 
// When debugging this should be USB. In production this should be MIDI
// This needs to be omnipresent in IOPDATA write operations.
#define 	USB								0
#define 	MIDI							1 << 17

// Gabe, add PRESSED and RELEASED in global_defs as #defines.
#define 	PRESSED 		1
#define		RELEASED		0


// E7T IOPCON defines (New Keydevice Driver)
#define		OCTOPUS_IOPCON_KEYINTR_RISING	0x1D <<  0
#define		OCTOPUS_IOPCON_KEYINTR_FALLING	0x1E << 10
#define		OCTOPUS_IOPCON_ROTINTR_RISING	0x1D <<  5
	
// HARDWARE - Section for Hardware enablement
//
#define 	SELECT_LED_DEVICE		1<<11
#define 	RESET_KEY				6<<11
#define 	SELECT_KEY_MSB_DEVICE	2<<11
#define 	SELECT_KEY_LSB_DEVICE	3<<11
#define 	SELECT_ROTARY_DEVICE	4<<11
#define 	SELECT_NOP_DEVICE		0<<11
#define 	RESET_ROTARY_COUNTERS	5<<11

#define 	IMPULSE_HIGH			1<<14
#define 	IMPULSE_LOW				0<<14

#define 	CLOCK_LR_HIGH			1<<15
#define 	CLOCK_LR_LOW			0<<15

#define 	CLOCK_KEY_LOW			0<<16
#define 	CLOCK_KEY_HIGH			1<<16

// Some syntactical sugar
#define 	LSB	0
#define 	MSB 5

#define 	INC 2
#define 	DEC 1



