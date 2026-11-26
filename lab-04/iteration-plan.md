# Iteration Plan (Weeks 5 to 14) · Team CertifiedVibeCoder
Version 1.0 · 2026-11-26 · Lead: Scrum Master (Sprint 1: Sok Chungseang)
---
## 1. Semester Gantt Chart (Mermaid)
```mermaid
gantt
    title ITC Club Hub · Iteration Plan (Weeks 5 to 14)
    dateFormat YYYY-MM-DD
    axisFormat %d %b
    tickInterval 1week
    weekday monday
    excludes weekends
    section Requirements
    Elicitation interview with the client       :req1, 2026-11-02, 5d
    SRS and product backlog                     :req2, after req1, 5d
    section Models
    Process setup and UML diagrams              :mod1, 2026-11-16, 10d
    section Checkpoint
    Midterm exam week (Week 9, no sprint work)  :crit, exam, 2026-11-30, 5d
    Checkpoint 1                                :milestone, cp1, 2026-12-04, 0d
    section Sprint 1
    Sprint 1 planning                           :milestone, s1_plan, 2026-12-07, 0d
    Sprint 1 development                        :s1_dev, 2026-12-07, 10d
    Sprint 1 review and retrospective           :milestone, s1_rev, 2026-12-18, 0d
    section Sprint 2
    Sprint 2 planning                           :milestone, s2_plan, 2026-12-21, 0d
    Sprint 2 development                        :s2_dev, 2026-12-21, 10d
    Sprint 2 review and retrospective           :milestone, s2_rev, 2027-01-01, 0d
    section Hardening
    Bug fixes only and feature freeze           :hard1, 2027-01-04, 4d
    section Submission
    Final Demo Project and submission           :milestone, sub, 2027-01-08, 0d
    section Labs
    Lab04 Software Processes (due 26 Nov)       :lab04, 2026-11-19, 6d
    Lab05 Requirements and SRS                  :lab05, 2026-12-07, 5d
    Lab06 Architecture and UML                  :lab06, 2026-12-14, 5d
    Lab07 Implementation and Persistence        :lab07, 2026-12-21, 5d
    Lab08 Testing and Quality                   :lab08, 2026-12-28, 5d
    Integration & Testing                       :int_test, 2026-12-07, 25d
```
---
## 2. Iteration Goals and Capacity Table
### Capacity Formula:
$$\text{Capacity} = \text{Members (5)} \times \text{Hours/Week (6)} \times \text{Duration (2 weeks)} \times 0.8\text{ (Focus Factor)} = \mathbf{48\text{ h}}$$
| Iteration | Weeks | Calendar Dates | Parallel Lab / Event | Goal | Candidate Features | Capacity | Exit Criterion |
| :--- | :---: | :---: | :---: | :--- | :--- | :---: | :--- |
| **Requirements** | 5–6 | Nov 02 – Nov 13 | Earlier labs (Lab02/Lab03) | Interview the client to clarify Club Hub rules and draft the initial SRS and backlog. | Student & club-lead user stories, domain rules. | 5 × 6 × 2 × 0.8 = 48 h | Initial SRS and prioritized product backlog reviewed by the team. |
| **Models & Process** | 7–8 | Nov 16 – Nov 27 | **Lab04 (due Nov 26)** | Finalize process decisions (PDR-001) and design Club Hub's domain and interaction UML models. | PDR-001, rapidcsv/GoogleTest smoke setup, use-case & domain class diagrams. | 5 × 6 × 2 × 0.8 = 48 h | Lab04 submitted by Nov 26 and UML models aligned with Must-have requirements. |
| **Checkpoint 1** | 9 | Nov 30 – Dec 04 | **Midterm Exam** | Pause sprint development for Week 9 midterm exams and pass the Checkpoint 1 review. | Checkpoint readiness check and specification/model audit (no sprint coding). | 0 h sprint (~8 h prep) | Checkpoint 1 deliverables accepted by the TA/instructor on Dec 04. |
| **Sprint 1** | 10–11 | Dec 07 – Dec 18 | Lab05 (Wk 10), Lab06 (Wk 11), Integration & Testing | Deliver a working CLI slice where students load CSV events, browse upcoming sessions, and register. | rapidcsv event loader, browse/list CLI view, registration with capacity & duplicate checks. | **48 h** (5 × 6 × 2 × 0.8) | Sprint 1 Must stories demoed to the TA on Dec 18 with all GoogleTest unit tests green in CI. |
| **Sprint 2** | 12–13 | Dec 21 – Jan 01 | Lab07 (Wk 12), Lab08 (Wk 13), Integration & Testing | Add 24-hour cancellation enforcement, club event creation, CSV save-back, and monthly summaries. | Cancel booking (>= 24 h cutoff), club event creation, CSV write-back, monthly club report. | **48 h** (5 × 6 × 2 × 0.8) | Changes persist across CLI runs, full CTest suite passes, and Sprint 2 demo is accepted on Jan 01. |
| **Hardening & Submission** | 14 | Jan 04 – Jan 08 | Final Demo Project, Integration & Testing | Freeze features to fix final defects, polish documentation, and deliver the Final Demo Project. | Malformed CLI/CSV input guards, regression check, CHANGELOG.md, v1.0.0 release tag & live demo. | 5 × 6 × 1 × 0.8 = 24 h | Zero open critical/major bugs, v1.0.0 merged & tagged on main, and Final Demo completed on Jan 08. |
