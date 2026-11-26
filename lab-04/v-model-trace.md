# V-Model Trace · REQ-12 Cancellation Deadline

Version 1.0 · 2026-11-26 · Bonus Challenge


---
## 1.Requirement

REQ-12: A student can cancel a registration until 24 hours before the start of the event.

Business rule:
- Cancellation is allowed when the remaining time before the event is at least 24 hours.
- Cancellation is rejected when less than 24 hours remain before the event.

## 2.V-Model Traceability

| Level | Left side (defines) | Right side (tests) |
|---------|---------|---------|
| Requirement | REQ-12: Student may cancel until 24 hours before event start. | AT-12 Acceptance Test: cancellation exactly 24 h before is accepted; cancellation at 23 h 59 m 59 s before is rejected. |
| System specification | RegistrationService::cancel(studentId,eventId) validates the 24-hour rule and updates registration status. | ST-12 System Test: execute cancel command through CLI and verify registration status and seat availability. |
| Architecture design | RegistrationService uses RegistrationRepository and EventRepository to obtain event date/time and registration data. | IT-12 Integration Test: repositories provide event information, service correctly applies deadline and persists changes. |
| Module design | canCancel(now,start) in include/clubhub/CancellationPolicy.hpp | UT-12a: now = start − 24 h → true. UT-12b: now = start − 24 h + 1 s → false. UT-12c: now = start − 7 d → true. UT-12d: now > start → false. |

## 3.Boundary Value Analysis

| Test ID | Input | Expected Result |
|-----------|--------|----------------|
| BV-01 | exactly 24 hours before start | Allowed |
| BV-02 | 23 h 59 m 59 s before start | Rejected |
| BV-03 | 7 days before start | Allowed |
| BV-04 | after event start | Rejected |

## 4.Gherkin Acceptance Scenarios (BDD)


```gherkin
Feature: Cancel a registration (REQ-12)

Background:
  Given the event "Robotics Workshop" starts on 2026-11-07 at 14:00
  And student "S001" is registered for "Robotics Workshop"

Scenario: Cancellation exactly 24 hours before the start is allowed
  Given the current time is 2026-11-06 14:00
  When student "S001" cancels the registration
  Then the registration status is "Cancelled"
  And one seat becomes free

Scenario: Cancellation less than 24 hours before the start is rejected
  Given the current time is 2026-11-06 14:00:01
  When student "S001" cancels the registration
  Then the registration status remains "Registered"
  And the message "Cancellation deadline has passed" is shown
  And no seat becomes free
```
