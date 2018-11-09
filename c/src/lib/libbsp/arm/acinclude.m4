# RTEMS_CHECK_BSPDIR(RTEMS_BSP_FAMILY)
AC_DEFUN([RTEMS_CHECK_BSPDIR],
[
  case "$1" in
  seerstm32f4 )
    AC_CONFIG_SUBDIRS([seerstm32f4]);;
  stm32f4 )
    AC_CONFIG_SUBDIRS([stm32f4]);;
  *)
    AC_MSG_ERROR([Invalid BSP]);;
  esac
])
