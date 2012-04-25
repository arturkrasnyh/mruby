#include <stdlib.h>
#include <stdio.h>

/* Include the mruby header */
#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
// to be replaced by #include <mruby/compile.h>
#include <compile.h>

int main(void)
{
  struct mrb_parser_state *p;
  mrb_state *mrb = mrb_open();
  char code[] = "p 'hello world!'";
  printf("Executing Ruby code from C!\n");

  p = mrb_parse_string(mrb, code);
  int n;
  n = mrb_generate_code(mrb, p->tree);
  mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_top_self(mrb));
  if (mrb->exc) {
		mrb_p(mrb, mrb_obj_value(mrb->exc));
  }
  return 0;
}
