# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-11 · Authors: Oeung Keangheang

Scope: the PWA from ADR-001 (students, organisers, administrators). The command-line front end follows `cli-output-rules.md`.

## 1. Success criteria

| SC | Name | Level | Screen | How we meet it | How we test it |
|----|------|-------|--------|----------------|----------------|
| **Perceivable** | | | | | |
| 1.1.1 | Non-text Content | A | event list | Club logos have alt text with the club name. Decorative icons use `alt=""`. | Screen reader (NVDA, TalkBack) reads each card once, with no "image" noise. |
| 1.3.1 | Info and Relationships | A | event list, registration form | Events are an HTML list of headings and text. Every form field has a `<label for>`. | Turn off CSS and check the order still makes sense. Inspect that labels are linked. |
| 1.4.1 | Use of Color | A | event list | Status badge carries text ("Full", "Open", "Cancelled") plus an icon. Colour only repeats it. | View the page in greyscale. Every status is still readable. |
| 1.4.3 | Contrast (Minimum) | AA | event list, registration form | Text colours chosen from the measured palette in section 2. | Contrast checker on every text and background pair. Text needs 4.5:1. |
| 1.4.10 | Reflow | AA | event list | One-column layout at 320 px wide. No horizontal scrolling. | Zoom the browser to 400 % at 1280 px width. Nothing is cut off. |
| 1.4.11 | Non-text Contrast | AA | registration form | Input borders, buttons and the focus ring are at least 3:1 against the page. | Contrast checker on borders and focus ring (section 2). |
| **Operable** | | | | | |
| 2.1.1 | Keyboard | A | registration form | Everything works with Tab, Shift+Tab, Enter and Space. No keyboard trap. | Complete a registration without a mouse. |
| 2.4.7 | Focus Visible | AA | all screens | 3 px focus ring on every control, never removed with `outline: none`. | Tab through the page and see where focus is at each step. |
| 2.4.11 | Focus Not Obscured (Minimum) | AA | event list | Sticky header and the offline banner do not cover the focused control. `scroll-padding-top` equals the header height. | Tab to the last card at 200 % zoom. The focused card is not hidden. |
| 2.5.7 | Dragging Movements | AA | event list, organiser check-in | No feature needs dragging. Sorting uses a menu. Check-in uses a button per student. | Search the design for drag and swipe gestures. Each has a button alternative. |
| 2.5.8 | Target Size (Minimum) | AA | registration form | Buttons and checkboxes are at least 44 × 44 CSS px, which is above the 24 × 24 minimum. | Browser dev tools, measure the Register, Cancel and Check-in buttons. |
| **Understandable** | | | | | |
| 3.1.1 | Language of Page | A | all screens | `<html lang="en">`. Khmer text, if added, uses `lang="km"` on that element. | Inspect the page source. Screen reader switches voice correctly. |
| 3.2.6 | Consistent Help | A | all screens | A "Help" link to the clubs office contact sits in the same footer position on every page. | Open five screens and compare the position of the Help link. |
| 3.3.1 | Error Identification | A | registration form | Errors are written in text next to the field and in a summary at the top. | Submit an empty form. The screen reader announces each error. |
| 3.3.7 | Redundant Entry | A | registration form | Name, student ID and email are filled from the student's profile. The student never retypes data already given. | Register for two events in a row. No field asks for the same data twice. |
| 3.3.8 | Accessible Authentication (Minimum) | AA | sign-in | Sign-in uses student ID plus an emailed one-time link. No puzzle or memory test. Pasting into fields is allowed. | Sign in with a password manager and by pasting the code. |
| **Robust** | | | | | |
| 4.1.2 | Name, Role, Value | A | registration form | Native `<button>`, `<input>` and `<select>` elements. ARIA only where no native element exists. | Accessibility tree in dev tools shows name and role for each control. |
| 4.1.3 | Status Messages | AA | registration form | "Registered", "Event is full" and "Saved offline" appear in an `aria-live="polite"` region. | The screen reader announces the message without moving focus. |

Coverage: 18 criteria. Perceivable 6, Operable 5, Understandable 5, Robust 2. All six WCAG 2.2 additions are included (2.4.11, 2.5.7, 2.5.8, 3.2.6, 3.3.7, 3.3.8).

## 2. Two screens: design decisions and contrast

Ratios were calculated with the WCAG relative-luminance formula. Re-check each pair in the WebAIM Contrast Checker and paste a screenshot of the result before submission.

### Screen A: event list

Design decisions
1. **Status as words.** Each card shows a badge reading "Open", "Full" or "Cancelled" with an icon. Colour only repeats the word (1.4.1).
2. **One column, large targets.** Cards stack in one column at narrow widths. The Register button is 44 px tall (1.4.10, 2.5.8).
3. **Dates in full.** Dates read "Tue 14 Oct 2026, 17:30", never "14/10" (3.3.2, and no ambiguity between day and month).

| Pair | Foreground | Background | Ratio | Requirement | Result |
|------|-----------|------------|-------|-------------|--------|
| Body text | #1F2933 | #FFFFFF | 14.76:1 | 4.5:1 | Pass |
| Secondary text (club name, location) | #52606D | #FFFFFF | 6.46:1 | 4.5:1 | Pass |
| "Full" badge text | #FFFFFF | #B42318 | 6.57:1 | 4.5:1 | Pass |
| "Open" badge text | #FFFFFF | #067647 | 5.69:1 | 4.5:1 | Pass |
| Card border | #6B7280 | #F8FAFC | 4.62:1 | 3:1 (UI component) | Pass |

### Screen B: registration form

Design decisions
1. **Visible labels and prefilled fields.** Every field has a label above it, and profile data is prefilled so nothing is retyped (1.3.1, 3.3.7).
2. **Errors in text, not only colour.** An error reads "Error: choose an event. Next step: pick one from the list", in red with an icon, and is announced by the live region (3.3.1, 4.1.3).
3. **Strong focus ring.** A 3 px blue ring on all controls, kept clear of the sticky header (2.4.7, 2.4.11).

| Pair | Foreground | Background | Ratio | Requirement | Result |
|------|-----------|------------|-------|-------------|--------|
| Button text | #FFFFFF | #1D4ED8 | 6.70:1 | 4.5:1 | Pass |
| Button against page | #1D4ED8 | #FFFFFF | 6.70:1 | 3:1 (UI component) | Pass |
| Input border | #6B7280 | #FFFFFF | 4.83:1 | 3:1 (UI component) | Pass |
| Focus ring | #1D4ED8 | #FFFFFF | 6.70:1 | 3:1 (UI component) | Pass |
| Error text | #B42318 | #FEF3F2 | 6.05:1 | 4.5:1 | Pass |

## 3. Open points
- Khmer interface text is not planned yet. If added, check font size and line height for Khmer script.
- The offline check-in queue (ADR-001) needs a visible "saved offline" state announced by the live region. Add a backlog item.