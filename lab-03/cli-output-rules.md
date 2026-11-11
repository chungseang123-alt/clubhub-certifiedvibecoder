# CLI output rules · ITC Club Hub
Version 0.1 · 2026-11-11 · Authors: <Oeung Keangheang>

These rules apply to the `clubhub` command-line front end. They support users who are colour-blind, use a screen reader or a braille display, work in a plain terminal, or pipe output into a file. The helpers in `include/clubhub/ConsoleOutput.h` implement rules 1, 2 and 3.

## Rule 1: Never give meaning by colour alone
The status is always written as a word. Colour may repeat it.

```text
bad : E-017  Git Workshop                 (shown in red)
good: E-017  Git Workshop      [CANCELLED]
```

## Rule 2: Honour NO_COLOR and a --no-color flag
Colour is on only if the flag is absent and `NO_COLOR` is unset or empty (no-color.org). Colour is also off when output is not a terminal.

```text
bad : always prints "\x1b[31mCANCELLED\x1b[0m", even into a file or a log
good: clubhub list --no-color        ->  [CANCELLED]
      NO_COLOR=1 clubhub list        ->  [CANCELLED]
```

## Rule 3: An error says what failed, why, and the next step

```text
bad : ERR_CAP
good: Error: cannot register for E-017: the event is full (40 of 40 seats).
      Next step: clubhub waitlist E-017
```

## Rule 4: A non-zero exit code on error, and errors go to stderr
Scripts and assistive tools rely on the exit code. Normal results go to stdout, errors to stderr.

```text
bad : prints "Error: event is full" and exits with code 0
good: prints "Error: ..." to stderr and exits with code 1
      (usage mistakes use 2, so a script can tell them apart)
```

## Rule 5: A prompt states the expected format and the default

```text
bad : Date?
good: Event date and time (YYYY-MM-DD HH:MM, for example 2026-10-14 17:30):
bad : Send SMS reminders? (y/n)
good: Send SMS reminders? [y/N] (default: no)
```

## Rule 6: Unambiguous dates and times
Use ISO 8601 order, 24-hour time and, where space allows, the weekday. Never `14/10` or `10/14`, and never "5 pm".

```text
bad : Starts 10/11 5pm
good: Starts 2026-10-14 17:30
```

## Rule 7: One record per line, plain text, no layout tricks
A screen reader reads left to right and line by line. Do not draw boxes or use dozens of spaces to align columns. Do not use symbols that are read aloud as noise.

```text
bad : ╔════════╦══════════╗
      ║ E-017  ║ ✖ ✖ ✖    ║
good: E-017  Git Workshop  2026-10-14 17:30  [CANCELLED]
```

## Rule 8: Progress and results are written, not animated
A spinner redraws the line and is unreadable on a braille display or in a log. Print a short line when work starts and a line when it ends.

```text
bad : \r| / - \ (spinner, then the line is overwritten)
good: Exporting monthly report...
      Done: 12 clubs written to reports/2026-10.csv
```