// DESCRIPTION: Verilator: Systemverilog example module
// with interface to switch buttons, LEDs, LCD and register display

parameter NINSTR_BITS = 32;
parameter NBITS_TOP = 8, NREGS_TOP = 32, NBITS_LCD = 64;
module top(input  logic clk_2,
           input  logic [NBITS_TOP-1:0] SWI,
           output logic [NBITS_TOP-1:0] LED,
           output logic [NBITS_TOP-1:0] SEG,
           output logic [NBITS_LCD-1:0] lcd_a, lcd_b,
           output logic [NINSTR_BITS-1:0] lcd_instruction,
           output logic [NBITS_TOP-1:0] lcd_registrador [0:NREGS_TOP-1],
           output logic [NBITS_TOP-1:0] lcd_pc, lcd_SrcA, lcd_SrcB,
             lcd_ALUResult, lcd_Result, lcd_WriteData, lcd_ReadData, 
           output logic lcd_MemWrite, lcd_Branch, lcd_MemtoReg, lcd_RegWrite);


logic [3:0] count;
logic reset;

// boolean para carregar
logic load;
// valor a ser carregado
logic [3:0] load_content
// boolean para contador decrescente
logic reverse

// always_comb para as entradas
always_comb begin
  reset <= SWI[7];
  load <= SWI[6];
  load_content <= SWI[3:0];
end

always_ff@(posedge clk_2) begin
  if(reset) begin
    count <= 0;
    revese <= 0;
  end
  else begin
    if (load) begin
        count <= load_content;
    end
    else begin
        if (!reverse) begin
            count <= count + 1;
        end
        else begin
            count <= count - 1;
        end

        // Caso chegue em 14, ele vai escrever o 15 antes de
        // começar a contar em ordem decrescente
        if (count == 14) begin
            reverse <= 1;
        end
        // O mesmo pro 1, ele escreve o 0 antes de contar de 
        // forma crescente
        else if (count == 1) begin
            reverse <= 0;
        end
        else begin
            reverse <= reverse;
        end
    end
  end
end


// Always_comb para as saídas
always_comb begin

// Mostrar o clock no LED 7
LED[7] <= clk_2;

// Mostrar o contador nos leds
LED [3:0] <= count;


// Mostrar os numeros nos 7 segmentos
  case(contador)
    0: SEG[7:0] <= 'b00111111;
    1: SEG[7:0] <= 'b00000110;
    2: SEG[7:0] <= 'b01011011;
    3: SEG[7:0] <= 'b01001111;
    4: SEG[7:0] <= 'b01100110;
    5: SEG[7:0] <= 'b01101101;
    6: SEG[7:0] <= 'b01111101;
    7: SEG[7:0] <= 'b00000111;
    8: SEG[7:0] <= 'b01111111;
    9: SEG[7:0] <= 'b01101111;
    10: SEG[7:0] <= 'b01110111;
    11: SEG[7:0] <= 'b01111100;
    12: SEG[7:0] <= 'b00111001;
    13: SEG[7:0] <= 'b01011110;
    14: SEG[7:0] <= 'b01111001;
    15: SEG[7:0] <= 'b01110001;
    default: SEG[7:0] <= 'b10000000;
  endcase
end



endmodule
