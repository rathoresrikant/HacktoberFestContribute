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

parameter msb_8bits = 7, msb_answer = 5, msb_signed_ab = 2;
parameter underflow_value = -4, overflow_value = 3, num_4 = 4;

logic incorrect;
logic [1:0] controller;
logic unsigned [msb_signed_ab:0] unsigned_a, unsigned_b;
logic signed [msb_signed_ab:0] a,b;
logic signed [msb_answer:0] answer;

always_comb begin
	a <= SWI[msb_8bits:msb_answer];
	b <= SWI[msb_signed_ab:0];
	controller <= SWI[num_4:overflow_value];

	unique case (controller)
		2'b00:
		begin
			answer[msb_signed_ab:0] <= (a+b);
			answer[msb_answer:3] <= 3'b000;
			incorrect <= ((a+b) < underflow_value) || ((a+b) > overflow_value);
		end

		2'b01:
		begin
			answer[msb_signed_ab:0] <= (a-b);
			answer[msb_answer:3] <= 3'b000;
			incorrect <= ((a-b) < underflow_value) || ((a-b) > overflow_value);
		end

		2'b10:
		begin
			answer[msb_answer:0] <= (unsigned_a*unsigned_b);
			incorrect <= 0;
		end

		2'b11:
		begin
			answer[msb_answer:0] <= (a*b);
			incorrect <= 0;
		end

	endcase

	LED[msb_answer:0] <= answer [msb_answer:0];
	LED[msb_8bits] <= incorrect;

	if (controller[1] == 0)
	begin
		unique case(signed'(answer[msb_signed_ab:0]))
			-4:SEG[msb_8bits:0] <= 8'b11100110;
			-3:SEG[msb_8bits:0] <= 8'b11001111;
			-2:SEG[msb_8bits:0] <= 8'b11011011;
			-1:SEG[msb_8bits:0] <= 8'b10000110;
			0:SEG[msb_8bits:0] <= 8'b00111111;
			1:SEG[msb_8bits:0] <= 8'b00000110;
			2:SEG[msb_8bits:0] <= 8'b01011011;
			3:SEG[msb_8bits:0] <= 8'b01001111;
		endcase

	end else begin
		SEG[msb_8bits:0] <= 8'b10000000;
	end

end

endmodule
