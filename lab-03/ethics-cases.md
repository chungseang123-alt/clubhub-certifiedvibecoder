# Ethics case analyses · ITC Club Hub
Version 1.0 · 2026-11-11 · Leads: A = <name>, B = Pheng Sopheak

## Scenario A: "Just a small report"
| Step | Analysis |
|------|----------|
| 1 Facts | TODO (and what we still need to find out) |
| 2 Stakeholders and harms | TODO |
| 3 Codes, law, policy | SE Code principle TODO; ACM TODO; GDPR TODO |
| 4 Options | (a) TODO (b) TODO (c) TODO |
| 5 Tests | harm / rights / fairness / publicity for each option |
| 6 Decision and action | TODO |
| 7 Reflection | TODO |

**Message sent:** TODO (max. 120 words)
**Preventive change:** TODO, issue #TODO

## Scenario B: "Don't mention it in the demo"
| Step | Analysis |
|------|----------|
| 1 Facts | Two days before the Sprint 1 review, a developer found two defects: (1) cancellations inside the 24-hour window are still accepted, which breaks our own business rule; (2) the monthly report counts cancelled registrations as attendance, so the numbers are wrong. The Scrum Master says: "Don't mention it in the demo, we'll fix it in Sprint 2. The client will never notice." We still need to find out: how long the fix takes, whether it can be done in two days, and whether any real data is already wrong. |
| 2 Stakeholders and harms | Client (clubs office and administrators): may make decisions from wrong reports and feel deceived later. Students: may be counted wrongly or lose a place. Club leaders: get wrong attendance numbers. The developer: may feel pressure to stay silent. Scrum Master and Product Owner: lose trust if the client finds out. Our team: loses its reputation for honesty. |
| 3 Codes, law, policy | SE Code principle 3 Product (software should meet high professional standards and be honest about its state); SE Code principle 6 Profession, item 6.12 (raise concerns about violations with the people involved); ACM Code 1.3 (be honest and trustworthy); GDPR accuracy principle (personal data such as attendance records must be correct). |
| 4 Options | (a) Stay silent as the Scrum Master asked. (b) Postpone the whole demo. (c) Do the demo as planned, but state both defects and the fix date in a "known issues" section. (d) Fix the rule in the two days and drop another item from the demo. |
| 5 Tests | (a) Harm: fails, wrong reports hurt the client's decisions. Rights: fails, the client has a right to know the real state of the product. Fairness: fails, we hide what we know from them. Publicity: fails, the client would feel deceived when the reports turn out wrong. (b) Harm: passes. Rights: passes. Fairness: passes. Publicity: passes, but it wastes the review and protects nothing extra. (c) Harm: passes. Rights: passes. Fairness: passes. Publicity: passes. (d) Harm: passes. Rights: passes. Fairness: passes. Publicity: passes, but only if the fix and its test fit in the time. |
| 6 Decision and action | Choose (c), and also (d) if the regression test is green by Thursday. The developer first raises it with the Scrum Master (SE Code 6.12), then the Product Owner puts it on the review agenda. |
| 7 Reflection | "The client will never notice" is not a good reason to hide a defect. The pressure came from the deadline, not from bad intentions. Next time we add a "known issues" section to every review, so honest reporting is normal and nobody feels they must hide problems. |

**Message sent:** Hi Scrum Master and Product Owner, while testing we found two defects: cancellations inside the 24-hour window are still accepted, and the monthly report counts cancelled registrations as attendance. We should not hide this from the client, because wrong reports would make them feel deceived later. We suggest: (1) show both defects in a "known issues" section at the demo, with a fix date; (2) try to fix them before Thursday and add regression tests. If the tests pass, we demo the fixed version. Can we decide this tomorrow and add it to the review agenda? Thanks,Pheng Sopheak

**Preventive change:** Add a regression test for the 24-hour cancellation rule, add a test that cancelled registrations are not counted in the monthly report, and add a "known issues" section to the review template. GitHub issue #4