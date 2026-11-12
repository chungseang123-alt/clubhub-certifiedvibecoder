# Lab-03 · Record of what changed

| File | Task | Status |
|------|------|--------|
| lab03/data-inventory.md | 1 | new |
| lab03/privacy-notice.md | 2 | new |
| lab03/consent-flow.mmd | 2 | new |
| include/clubhub/Student.h | 2 | new |
| tests/StudentPrivacyTest.cpp | 2 | new |
| lab03/license-decision.md | 3 | new| 
| licenses/googletest-LICENSE.txt | 3 | new|
| lab03/accessibility-checklist.md | 4 | new|
| lab03/cli-output-rules.md | 4 | new|
| src/ConsoleOutput.cpp | 4 | new  |
| tests/ConsoleOutputTest.cpp | 4 | new  |
|  include/clubhub/ConsoleOutput.h | 4 | new  |
| lab03/ethics-cases.md  | 5 | new  |
| lab03/ai-feature-proposal.md | Challenge | new|

## Inputs reused
| Input | File | Version / commit |
|-------|------|------------------|
| Team charter | lab01/<charter file> | <hash> (git log -1 --format=%h -- lab01) |
| Application type | lab02/<application-type file> | <hash> (git log -1 --format=%h -- lab02) |

## Change log
| Date | Change | Author |
|------|--------|--------|
| 2026-11-11 | Lab-03/Task 1: Data inventory with minimisation decisions | Sok Chungseang |
| 2026-11-11 | Lab-03/Task 2: Privacy notice, consent, retention and a privacy-aware | Sok Chungseang |
| 2026-11-11 | Lab-03/Task 3: Choose and apply a licence for the team repository | Seng Sarak |
| 2026-11-11 | Lab-03/Task 4: Accessibility review: WCAG 2.2 checklist and CLI output rules | Oeung Keangheang |
| 2026-11-11 | Lab-03/Task 5: Ethics case analysis and "Record what changed" | Pheng Sopheak & Song PanhaSeth |
| 2026-11-11 | Lab-03/Challenge: AI feature proposal, recommended events | Oeung Keangheang |

## Open questions for the client
1. Attendance retention. Individual check-in rows are deleted after a month and only monthly club totals remain. Is that enough for the clubs office, or does it need a longer, consent-based history (see ai-feature-proposal.md)?
2. Graduation date. Phone numbers are erased six months after graduation. Which system holds the graduation date, and can Club Hub read it without storing more personal data?
3. Emergency contact. Is contacting a student about an incident a real requirement? If yes, it needs its own legal basis and cannot rely on the SMS opt-in.
4. Sponsors. May sponsors ever receive attendance numbers or student contact details? The inventory assumes no, and only monthly club totals are shared.
