AC_DEFUN([_RTEMS_CPU_SUBDIR],
[
$1 )	if test -d ${srcdir}/ifelse([$2],,[$1],[$2/$1]) ; then
  AC_CONFIG_SUBDIRS(ifelse([$2],,[$1],[$2/$1]))
  fi
])

## RTEMS_CPU_SUBDIRS([PREFIX])
AC_DEFUN([RTEMS_CPU_SUBDIRS],
[
## EDIT: If adding a new cpu to RTEMS, add it to the case block below.
case $RTEMS_CPU in
_RTEMS_CPU_SUBDIR([arm],[$1]);;
*) AC_MSG_ERROR([Invalid RTEMS_CPU <[$]{RTEMS_CPU}>])
esac
])
