/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.2
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#ifdef PACKAGE_NAME
#define CMDLINE_PARSER_PACKAGE_NAME PACKAGE_NAME
#else
#define CMDLINE_PARSER_PACKAGE_NAME PACKAGE
#endif
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * input_arg;	/**< @brief input file (default std input).  */
  char * input_orig;	/**< @brief input file (default std input) original value given at command line.  */
  const char *input_help; /**< @brief input file (default std input) help description.  */
  char * file_name_arg;	/**< @brief name used for generating file (default stdout).  */
  char * file_name_orig;	/**< @brief name used for generating file (default stdout) original value given at command line.  */
  const char *file_name_help; /**< @brief name used for generating file (default stdout) help description.  */
  char * gen_name_arg;	/**< @brief prefix for generated code (default='gengen').  */
  char * gen_name_orig;	/**< @brief prefix for generated code original value given at command line.  */
  const char *gen_name_help; /**< @brief prefix for generated code help description.  */
  char * output_format_arg;	/**< @brief target language (cpp, c) (default='cpp').  */
  char * output_format_orig;	/**< @brief target language (cpp, c) original value given at command line.  */
  const char *output_format_help; /**< @brief target language (cpp, c) help description.  */
  char * output_dir_arg;	/**< @brief output directory (default current dir).  */
  char * output_dir_orig;	/**< @brief output directory (default current dir) original value given at command line.  */
  const char *output_dir_help; /**< @brief output directory (default current dir) help description.  */
  const char *separate_files_help; /**< @brief output to separate files (header, source). require --file-name help description.  */
  const char *expand_tabs_help; /**< @brief strings containing newlines are indented according to the current indentation level help description.  */
  const char *no_gen_version_help; /**< @brief do not put gengen version in the generated file help description.  */
  const char *test_mode_help; /**< @brief even with errors exit with 0 (this is only for testing purposes) help description.  */
  const char *force_help; /**< @brief force regeneration of output code help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int input_given ;	/**< @brief Whether input was given.  */
  unsigned int file_name_given ;	/**< @brief Whether file-name was given.  */
  unsigned int gen_name_given ;	/**< @brief Whether gen-name was given.  */
  unsigned int output_format_given ;	/**< @brief Whether output-format was given.  */
  unsigned int output_dir_given ;	/**< @brief Whether output-dir was given.  */
  unsigned int separate_files_given ;	/**< @brief Whether separate-files was given.  */
  unsigned int expand_tabs_given ;	/**< @brief Whether expand-tabs was given.  */
  unsigned int no_gen_version_given ;	/**< @brief Whether no-gen-version was given.  */
  unsigned int test_mode_given ;	/**< @brief Whether test-mode was given.  */
  unsigned int force_given ;	/**< @brief Whether force was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char * const *argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
