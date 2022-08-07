/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "syslog.h"

/**
 * Generates a log message which will be distributed by syslogd
 *
 * Note: no errors are reported if an error occurred while logging
 *       the message.
 *
 * @param priority is a bitmask containing the facility value and
 *        the level value. If no facility value is ORed into priority,
 *        then the default value set by openlog() is used.
 *        it set to NULL, the program name is used.
 *        Level is one of LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
 *        LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG
 * @param message the format of the message to be processed by vprintf()
 * @param ap the va_list of arguments to be applied to the message
 * @asyncsignalsafe
 */
void vsyslog(int priority, const char *message, va_list ap) {
}

/**
 * Sets log priority mask
 *
 * Modifies the log priority mask that determines which calls to
 * syslog() may be logged.
 * Log priority values are LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
 * LOG_WARNING, LOG_NOTICE, LOG_INFO, and LOG_DEBUG.
 *
 * @param mask the new priority mask to use by syslog()
 * @return the previous log priority mask
 * @asyncsignalsafe
 */
int setlogmask(int maskpri) {
  int ret = maskpri;
  return ret;
}

/**
 * Opens a connection to the system logger
 *
 * Calling this function before calling syslog() is optional and
 * only allow customizing the identity, options and facility of
 * the messages logged.
 *
 * @param ident a string that prepends every logged message. If
 *        it set to NULL, the program name is used.
 * @param opt specifies flags which control the operation of openlog().
 *        Only the following flags are supported:
 *         LOG_CONS = Write directly to the system console if there is
 *                    an error while sending to the system logger.
 *         LOG_NDELAY = Open the connection with the system logger
 *                      immediately instead of waiting for the first
 *                      message to be logged.
 *         LOG_ODELAY = The converse of LOG_NDELAY.
 *         LOG_PERROR = Also log the message to stderr.
 *         LOG_PID = Include the caller's PID with each message
 * @param facility specifies the default facitlity value that defines
 *        what kind of program is logging the message.
 *        Possible values are: LOG_AUTH, LOG_AUTHPRIV,
 *        LOG_CRON, LOG_DAEMON, LOG_FTP, LOG_LOCAL0 through LOG_LOCAL7,
 *        LOG_LPR, LOG_MAIL, LOG_NEWS, LOG_SYSLOG, LOG_USER (default),
 *        LOG_UUCP.
 * @asyncsignalsafe
 */
void openlog(const char *ident, int opt, int facility) {
}

/**
 * Generates a log message which will be distributed by syslogd
 *
 * Note: no errors are reported if an error occurred while logging
 *       the message.
 *
 * @param priority is a bitmask containing the facility value and
 *        the level value. If no facility value is ORed into priority,
 *        then the default value set by openlog() is used.
 *        it set to NULL, the program name is used.
 *        Level is one of LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
 *        LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG
 * @param message the message formatted using the same rules as printf()
 * @asyncsignalsafe
 */
void syslog(int priority, const char *message, ...) {
}

/**
 * Closes the file descriptor being used to write to the system logger
 *
 * Use of closelog is optional
 * @asyncsignalsafe
 */
void closelog(void) {
}
