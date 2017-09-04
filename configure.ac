dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(gstreamer, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CXX




dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=gstreamer
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT





LT_INIT


PKG_CHECK_MODULES(GSTREAMER, [gstreamermm-1.0 gstreamer-video-1.0 gstreamer-riff-1.0 gstreamer-1.0 gstreamer-net-1.0 gstreamer-pbutils-1.0 gstreamer-app-1.0 gstreamer-audio-1.0 gstreamer-tag-1.0 gstreamer-plugins-base-1.0 gstreamer-rtsp-1.0 gstreamer-check-1.0 gstreamer-base-1.0 gstreamer-fft-1.0 gstreamer-sdp-1.0 gstreamer-rtp-1.0 glibmm-2.4 gstreamer-controller-1.0 ])




AC_OUTPUT([
Makefile
src/Makefile
po/Makefile.in
])
