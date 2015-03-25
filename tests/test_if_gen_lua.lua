
require("test_if_lua")

test_if_gen_table.myvar = "\"fooval\""
test_if_gen_table.mydef = "foodef";
test_if_gen_table.boolvar = 0;
test_if_gen_table.intvar = 0;
test_if_gen_table.intvarcomp = 0;
test_if_gen_table.stringvar = "bar";
test_if_gen_table.stringvarcomp = "ba";
generate_test_if(stdout, test_if_gen_table, 0);