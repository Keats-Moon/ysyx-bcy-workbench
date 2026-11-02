#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <nvboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void nvboard_bind_all_pins(TOP_NAME* top);

int main(int argc, char ** argv){
        VerilatedContext *ctx = new VerilatedContext;
        ctx -> commandArgs(argc, argv);
        ctx -> traceEverOn(true);

        Vtop *top = new Vtop{ctx};
        VerilatedFstC* tfp = new VerilatedFstC;
        top -> trace(tfp, 99);
        tfp -> open("wave.fst");

        nvboard_bind_all_pins(top);
        nvboard_init();

        while(1){
                nvboard_update();

                top -> eval();
                ctx -> timeInc(1);
                tfp->dump(ctx->time());

                printf("a=%d, b=%d, f=%d\n", top -> a, top -> b, top ->f);
                assert(top -> f == (top->a ^ top->b));

        }
        tfp -> close();
        delete tfp;

        top ->final();
        delete top;
        delete ctx;
        return 0;
}
