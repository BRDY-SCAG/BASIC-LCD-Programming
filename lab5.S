;;

;;  AVR code to do the function of the 4  x 7 segment display of Lab 5
;;
;;
;;   Brady Scaggari
;;    CS 273
;;    Semester SPRING , 2023
;;
;;  The basic algorithm is to have the main loop
;; set some shared variable values
;;  we then use simulataneous arrays (vectors)
;;  to figure out which segment is desired 
;;; and which sequence is needed
;;
;;  Since our setup utilizes PORTB and PORTB, then we need to main
;;   simulataneous vectors for all of the segment sequences that are neededed
;;
;; main routine does
;;   setup_ports once
;; 
;;   C code to do the following

;;   segment=0
;;   digit=9
;;   display_segment();; will display 9 on segment 0, for example
;;  
  .data
  .size segment_table, 4
  .size portb_table, 10
  .size portd_table, 10
  
//segment_table:  #binary for seting input on PORTB for segment select
//    .byte 0b00000010, 0b00000100, 0b00001000, 0b00010000
//    ;; 0, 1, 2,3 4, 5, 6 , 7, 8 , 9
//portb_table:  # list of binary sequences for setting port B to be ORed with segment table ite
//    .byte  0b00000001,1,0,0,0,0,0,1,0,0
//portd_table: # list of binary sequences for setting port D.
//    .byte  0b00000000,0b11100100,0b10010000,0b11000000,0b01100100,0b01001000,0b00001100,0b11100000,0, 0b01100000
segmentv: .byte 1


// For newer ELEGOO boards
segment_table: #binary for seting input on PORTB for segment select
.byte 0b11111100, 0b11111010, 0b11110110, 0b11101110
;; 0, 1, 2,3 4, 5, 6 , 7, 8 , 9
portb_table: # list of binary sequences for setting port B to be ORed with segment table
.byte 0,0,1,1,1,1,1,0,1,1
portd_table: # list of binary sequences for setting port D.
.byte 0b11111111,0b00011011,0b01101111,0b00111111,0b10011011,0b10110111,0b11110011,0b00011111,0b11111111, 0b10011111
//

  
  .comm segment, 1 ;; the common name for segment
  .comm digit, 1 ;; the digit into our sequences
  .global segment, digit

  

# --------
  .text
  .global setup_ports
  .global display_segment



setup_ports:  ;; routine to set the ports into output mode
   ;; set PORT B
   push R16 
   ldi R16, 0b00011111 // port b's jumpers
   out 0x04, R16
     ;; set PORT D
   ldi R16, 0b11111100
   out 0x0A, R16
   pop R16
  
   ret ;; of setup_ports



display_segment:  ;;  main entry point for setting the segment

   ;; the goal is the use "digit" to and "segment" to find the values that need
   ;; to be sent to PORTB and PORT D 

   push R31
   push R30
   push R29
   push R28
   push R19
   push R18
   push R17
   push R16

   ldi R31, hi8(segment_table) // z register with pointer to segment table 
   ldi R30, lo8(segment_table)

   lds R16, segment

loop:    LD R17, Z+
         cpi R16, 0
         BREQ NEXT
         DEC R16
         rjmp loop

NEXT:    out 0x05, R17   // port be set for segment


         ldi R31, hi8(portb_table)//Z
         ldi R30, lo8(portb_table)
         ldi R29, hi8(portd_table)//Y
         ldi R28, lo8(portd_table)

         lds R16, digit

dloop:  ld R18, Z+  // b_ table
        ld R19, Y+  // d_ table
        cpi R16, 0
        BREQ doit
        DEC R16
        rjmp dloop

doit:
         OR R17, R18
         out 0x05, R17
         out 0x0B, R19

   
   pop R16
   pop R17
   pop R18
   pop R19
   pop R28
   pop R29
   pop R30
   pop R31
   


    ret ;; of display_segment
    
