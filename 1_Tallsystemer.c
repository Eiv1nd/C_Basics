// --------------------------------------------------------
// 				Grunntall	Plassbestemt	Siffer	Notasjon
// Desimal			10 			Ja			0-9 	Ingen
// Binært			2 			Ja 			0-1 	0b
// Hexadesimalt		16 			Ja 			0-F 	0x
// --------------------------------------------------------


// --------------------------------------------------------
// Decimal		Binary 		Hexadecimal
// --------------------------------------------------------
// 0 			0000 		0
// 1 			0001 		1
// 2 			0010 		2
// 3 			0011 		3
// 4 			0100 		4
// 5 			0101 		5
// 6 			0110 		6
// 7 			0111 		7
// 8 			1000 		8
// 9 			1001 		9
// 10 			1010 		A
// 11			1011 		B
// 12 			1100 		C
// 13			1101 		D
// 14			1110 		E
// 15			1111 		F
// 16			10000 		10
// --------------------------------------------------------
// --------------------------------------------------------
// 7		6		5		4		3 		2 		1 		0
// 128 		64		32 		16 		8 		4 		2 		1
// 									1000	100		10		1
// 									4096 	256 	16 		1
// --------------------------------------------------------


// --------------------------------------------------------
// Negative tall
// I datamaskiner brukes 2-komplements form for å
// representere negative tall
// 2-komplement kan kun brukes når vi har et fast antall bit.
// Det første bitet (bit 7) brukes som fortegnsbit.
// 
// Finne ut verdien til 2-komplements negativt tall
// 1. n = 0x10110100
// 2. Komplementet til n er k = 01001011
// 3. m = k + 1 = 01001011 + 1 = 01001100 = 76
// 4. n = 0x10110100 er det samme som –76
// n = 10000000
// Komplementet = 01111111
// m = k + 1 = 10000000 = 128
// n = 10000000 = –128


// --------------------------------------------------------
// Addition i totallsystemet
//  111 1
//   10101
// + 01101
// ----------	
// =100010


// --------------------------------------------------------
// Binary multiplication
// 		101001·110
// 		----------
//  	000000
// 	   101001	 
//	  101001
// 	  ----------
//  = 11110110


// --------------------------------------------------------
// -- Bits -- Unsigned -- Two complement -- Ones complement
// --------------------------------------------------------
// 0111 1111	127			127				127
// 0111 1110	126			126				126
// 0000 0010 	2			2 				2
// 0000 0001 	1 			1 				1
// 0000 0000 	0 			0 				0
// 1111 1111 	255			-1 				-0
// 1111 1110 	254			-2 				-1
// 1000 0010	130			-126 			-125
// 1000 0001 	129			-127 			-126
// 1000 0000	128			-128 			-127
// --------------------------------------------------------


// ############ Omgjøringer ############
// --------------------------------------------------------
// Binært -> Desimalt
// 1100
// = 1·2^3 + 1·2^2 + 0·2^1 + 0·2^0
// = 1·8 + 1·4 + 0·2 + 0·1
// = 12
// --------------------------------------------------------
// Desimalt -> Binært
// 782
// = 512 + 256 + 8 + 4
// = 0x 0001 1000 1100
// Del tallet på 2
// rest -> skriv 1 til venstre
// ingen rest -> skriv 0 til venstre
// Desimalt		Rest? 	Binært
// 15:2 = 7.5	Ja 	 	1
// 7:2 = 3.5	Ja		11
// 3:2 = 1.5	Ja 		111
// 1:2 = 0.5	Ja  	1111
// --------------------------------------------------------
// Hexadesimalt -> Desimalt
// 3F6
// = 3·16^2 + 15·16^1 + 6·16^0
// = 3·256 + 15·16 + 6·1
// = 1014 
// --------------------------------------------------------
// Desimalt -> Hexadesimalt
// Desimalt				Oppmultiplisert		Rest	Hexadesimalt
// 12092:16 = 755.75	0.75*16 =			12			C
// 755:16 = 47.1875		0.1875*16 =			3			3C
// 47:16 = 2.9375		0.9375*16 =			15			F3C
// 2:16 = 0.125			0.125*16 =			2			2F3C
// 0			
// --------------------------------------------------------
// Binært -> Hexadesimalt
// Hexadesimalt -> Binært
// 0001 1111 0110 0100 =
// 1 	F    6 	  4


// --------------------------------------------------------
// ASCII Tabell
// Brukes for å kode karakterer/bokstaver
// 
// Dec    Hex 	Char
// 0 	  0 	NULL  
// 1 	  1 	Start of heading
// 2 	  2 	Start og text
// 3 	  3 	End of text
// 4 	  4 	End of transmission
// 5 	  5 	Enquiry
// 6 	  6 	Acknowledge
// 7 	  7 	Bell
// 8 	  8 	Backspace
// 9 	  9 	Horizontal tab
// 10 	  A 	Line feed
// 11	  B 	Vertical tab
// 12 	  C 	Form feed
// 13 	  D 	Carriage return
// 14	  E 	Shift out
// 15	  F 	Shift in
// 16	  10	Data link escape
// 17	  11	Device control 1
// 18	  12	Device control 1
// 19	  13	Device control 1
// 20	  14	Device control 1
// 21 	  15 	Negative Acknowledge
// 22	  16	Synchronous idle
// 23	  17	Eng of trans. block
// 24	  18	Cancel
// 25	  19	End of medium
// 26	  1A	Substitute
// 27	  1B	Escape
// 28	  1C	File separator
// 29	  1D	Group separator
// 30	  1E	Record separator
// 31	  1F	Unit separator


/**
32 	 		64 	@ 	96 		` 
33 		! 	65 	A	97 		a 
34 		" 	66 	B	98 		b 
35 		# 	67 	C	99 		c 
36 		$ 	68 	D	100 	d 
37 		% 	69 	E	101 	e 
38 		& 	70 	F 	102 	f 
39 		' 	71 	G	103 	g 
40 		( 	72 	H	104 	h 
41 		) 	73 	I	105 	i 
42 		* 	74 	J	106 	j 
43 		+ 	75 	K	107 	k 
44 		, 	76 	L	108 	l 
45 		- 	77 	M	109 	m 
46 		. 	78 	N	110 	n 
47 		/ 	79 	O	111 	o 
48 		0 	80 	P	112 	p 
49 		1 	81 	Q	113 	q 
50 		2 	82 	R	114 	r 
51 		3 	83 	S	115 	s 
52 		4 	84 	T	116 	t 
53 		5 	85 	U	117 	u 
54 		6 	86 	V	118 	v 
55 		7 	87 	W	119 	w 
56 		8 	88 	X	120 	x 
57 		9 	89 	Y	121 	y 
58 		: 	90 	Z	122 	z 
59 		; 	91 	[	123 	{ 
60 		< 	92 	\ 	124 	| 
61 		= 	93 	]	125 	} 
62 		> 	94 	^ 	126 	~ 
63 		? 	95 	_	127 	DEL 

*/
