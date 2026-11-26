# Process comparison · Team CertifiedVibeCoder · v1.0
Scale: 1 = fits badly, 5 = fits very well.
| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     25 |         2 |           4 |           5 | Core rules are in the brief, but CLI details and edge cases will evolve after week-5 elicitation and sprint demos. |
| Client availability     |     20 |         2 |           3 |           4 | The TA is available ~30 min every Friday: enough for a bi-weekly sprint review, not for daily questions. |
| Team experience         |     10 |         3 |           4 |           3 | The team is learning C++20, CMake, and Scrum ceremonies simultaneously, making small slices safer despite ceremony overhead. |
| Deadline (week 14)      |     30 |         1 |           4 |           5 | Week 14 is a hard deadline with week 8 blocked by midterms; two-week sprints guarantee working code early instead of risky late integration. |
| Risk                    |     15 |         2 |           4 |           5 | Early GoogleTest CI and Sprint 1 demos expose misunderstood business rules (like the 24-hour cancellation cutoff) well before week 13. |
| **Weighted score**      |    100 |      1.80 |        3.80 |        4.60 |                               |
## Why these weights
- Requirements stability (25): The case-study brief gives baseline registration and 24-hour cancellation rules, but detailed CLI stories emerge in week-5 elicitation and evolve after sprint demos.
- Client availability (20): Per the case-study brief, the TA/client is available for 30 minutes on Fridays, which constrains daily Q&A and rewards structured bi-weekly reviews.
- Team experience (10): Per our team charter, members are still gaining experience with C++20, CMake `FetchContent`, GoogleTest, and Scrum ceremonies, though weekly labs guide the tooling.
- Deadline (week 14) (30): The semester schedule sets a hard, immovable week-14 submission and demo (with week 8 blocked by midterm exams), making on-time delivery our top priority.
- Risk (15): Integrating CSV persistence, `std::chrono` 24-hour boundary rules, and parallel lab deliverables carries schedule and integration risks that must be caught early.

## Calculation for one model
Calculation, Scrum-style: 
$$\text{Weighted Score} = \sum \frac{(\text{Weight} \times \text{Score})}{100}$$
$$\begin{aligned}
\text{Scrum Score} &= \frac{(25 \times 5) + (20 \times 4) + (10 \times 3) + (30 \times 5) + (15 \times 5)}{100} \\
&= \frac{125 + 80 + 30 + 150 + 75}{100} \\
&= \frac{460}{100} = \mathbf{4.60}
\end{aligned}$$

*(Waterfall = 1.65 / 5.00 · Incremental = 3.80 / 5.00)*

## Sensitivity check
Moving 10 points from our heaviest criterion (Deadline: 30 → 20) to our lightest (Team experience: 10 → 20) recomputes the scores to Waterfall = 2.00, Incremental = 3.80, and Scrum-style = 4.40, so the winner does not change.

## Conclusion
Scrum-style iterative development scores best for Club Hub at 4.60, well ahead of Incremental delivery (3.80) and Waterfall (1.80). Its main weakness for Team CertifiedVibeCoder is Team experience (3/5), since running formal sprint planning, estimation, and retrospectives while learning C++20, CMake, and GoogleTest can eat into our limited weekly hours. We must manage this by keeping ceremonies strictly timeboxed and preparing concrete demo agendas for the TA's 30-minute Friday slot. A hybrid model would score even better in practice: combining structured up-front SRS and UML modelling in weeks 5–7 with two two-week Scrum sprints in weeks 9–12 and a dedicated week-13 hardening phase offsets our lower experience while preserving Scrum's adaptability and deadline safety.