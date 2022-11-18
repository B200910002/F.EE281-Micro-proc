 	LXI H, 2001H 
          MOV B, M     
          MVI C, 00       
          LXI H,2000H           
          MOV A, M        
NEXT: 
          CMP B           
          JC LOOP          
          SUB B           
          INR C          
          JMP NEXT         
LOOP:  
          STA 2011H       
          MOV A, C        
          STA 2010H          
          HLT    