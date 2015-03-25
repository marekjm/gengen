
require("example_text_lua")

init_example_text_gen_table(example_text_gen_table)
example_text_gen_table.name = "an example"
example_text_gen_table.progname = "example_text_gen"
example_text_gen_table.generator = "Gengen"
example_text_gen_table.version = "1.0"

generate_example_text(stdout, example_text_gen_table, 0)
print("\n")

example_text_gen_table.name = "another example"
io.write("  ")

generate_example_text(stdout, example_text_gen_table, 2)
io.write("\n")
