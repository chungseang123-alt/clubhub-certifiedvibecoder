# Problem statement · ITC Club Hub (v0.2, 2026-21-10)

## Problem
- The problem of informal event management, untracked student sign-ups, and unverified attendance affects ITC students, club leaders, event organisers, and university administrators; the impact of which is overbooked venues, double-registered participants, lack of attendance records, and zero administrative visibility across campus clubs.
- A successful solution would provide a centralized platform in the `clubhub` namespace to enforce strict business rules (capacity caps, 24-hour cancellation windows, unapproved club restrictions) and deliver accurate monthly activity reports.

## Vision
- For ITC students, club leaders, organisers, and administrators who need structured campus activity coordination, ITC Club Hub is a desktop CLI and future web/mobile platform that automates event publishing, student registrations, check-ins, and activity reporting.
- Unlike informal Telegram chat groups and unvalidated Google Sheets, our product strictly prevents duplicate registrations, enforces capacity limits (1–500), blocks registrations for past events, and requires administrator approval before a club can publish events.

## Today's workaround
Currently, club leaders announce events on Telegram, collect registrations using basic Google Forms without capacity caps, and manually track door attendance on paper. Administrators have no central way to view monthly club activity reports or verify if non-approved clubs are hosting events.

## Scope
- Built in C++ this semester:
  - C++20 domain model inside `namespace clubhub` managing clubs, events, registrations, and check-ins.
  - Business rule enforcement: capacity caps, blocking duplicate registrations, 24-hour cancellation cutoff, past event blocking, and approved-club publishing checks.
  - Command-line interface (CLI) with CSV/JSON file storage under `include/clubhub/` and `src/`.
- Modelled only (web and mobile):
  - Student mobile screens for event browsing, registration cancellation, and receiving event reminders.
  - Web UI for door organisers checking in students and administrators viewing monthly activity reports.
- Out of scope:
  - Real-time online payment processing for ticketed events.
  - Native iOS/Android compiled applications and SMS/push notification gateway integrations.
  - Single Sign-On (SSO) integration with external university LDAP servers.
