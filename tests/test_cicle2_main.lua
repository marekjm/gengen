
require("test_cicle2_lua.lua")
require("test_body_loop_lua.lua")

function generate_loop(stream, table, indent)
  table.my_start = "1"
  table.my_end = "10"
  generate_test_body_loop (stream, table, indent)
end

function generate_return_st(stream, table, indent)
end

test_cicle_gen_gen_table.loopnum = "10"
test_cicle_gen_gen_table.return_st = "return 0;"
generate_test_cicle_gen (stdout, test_cicle_gen_gen_table, 0)