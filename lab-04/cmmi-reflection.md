# CMMI Reflection · Team CertifiedVibeCoder ·

Version 1.0 · 2026-11-26 · Bonus Challenge


---

## 1.Where we are today (Level 1) and the evidence

Our team is currently operating close to CMMI Maturity Level 1 (Initial). We have established a Git repository, completed Lab-01 through Lab-04 artifacts, and maintain a commit history showing individual contributions. However, many activities still depend on informal communication. Requirements are evolving, estimates are not always documented, and traceability between requirements, design, and tests is still being introduced.

Evidence includes:
- Team charter and project repository.
- Git commit history from all members.
- Process decision record (PDR-001).
- Sprint and iteration planning documents.
- Automated tests using GoogleTest.

While our work is organized, processes are not yet consistently measured or managed across all activities.

## 2.The practice area we adopt now and why

We will adopt the CMMI practice area Requirements Management (REQM).

Requirements may change after sprint reviews and client feedback. The Club Hub project includes multiple business rules such as capacity limits, duplicate registration prevention, and the 24-hour cancellation deadline. Managing requirements systematically will reduce misunderstandings and rework.

## 3.Three actions (who, from when)

1. Product Owner:
   Assign a unique identifier to every requirement beginning in Sprint 1.

2. Scrum Master:
   Maintain traceability between requirements, backlog items, UML models, and tests beginning in Week 9.

3. Developers:
   Reference requirement IDs in pull requests and test cases for each implemented feature.

## 4.How we measure it (metric, target) and when we check

Metric:
Percentage of implemented user stories linked to a requirement ID.

Formula:
(Number of implemented stories with traceability links / Total implemented stories) × 100

Target:
100% traceability by the end of Sprint 1.

Review Date:
Sprint 1 Retrospective (Week 10).

If the target is not reached, corrective actions will be added to Sprint 2 planning.
