#####################################################
#
#  FILE: ax_sick_lms_1xx_src_dir.m4
#  AUTH: Robert Huitl
#  CONT: robert(at)huitl(dot)de
#  DATE: 9 June 2011
#
#  DESC: A macro for setting the lms 5xx source dir
#
#  NOTE: Assumes there is always an input arg
#
#####################################################
AC_DEFUN([AX_SICK_LMS_5XX_SRC_DIR], [
SICK_LMS_5XX_SRC_DIR=$1
AC_SUBST(SICK_LMS_5XX_SRC_DIR)
])dnl AX_SICK_LMS_5XX_SRC_DIR
