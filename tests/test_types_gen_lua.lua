
require("test_types_lua")

test_types_gen_table.mystring = "hello_world"
test_types_gen_table.myint = 1971
test_types_gen_table.mybool = 1
generate_test_types(stdout, test_types_gen_table, 0)