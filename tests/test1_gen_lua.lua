
require ("test1_lua")

test1_gen_table.i = "foo"
generate_test1(stdout, test1_gen_table, 0)
print("\n")
test1_gen_table.i = "bar"
generate_test1(stdout, test1_gen_table, 0)
print("\n")
