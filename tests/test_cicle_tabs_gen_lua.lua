
--[[
     rely on the generate_string method that expands tabs for strings
     in this case, the loop field
--]]

dofile("test_cicle_tabs_lua.lua")
dofile("test_body_loop_lua.lua")

test_body_loop_gen_table.my_start = "1"
test_body_loop_gen_table.my_end = "10"
loop_str = genstring_test_body_loop(test_body_loop_gen_table, 0)

test_cicle_gen_table.loopnum = "10"
test_cicle_gen_table.return_st = "return 0;"
test_cicle_gen_table.loop = loop_str

generate_test_cicle(stdout, test_cicle_gen_table, 0)