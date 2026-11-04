# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-30-10 · Reviewed by (Scrum Master): Sok Chungseang

## QAS-01 · Availability · written by Seng Sarak
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

## QAS-02 · Performance of check-in at the door · written by Pheng Sopheak
| Part             | Content |
|------------------|---------|
| Source           | A student arriving at an event who wants to check in at the door. |
| Stimulus         | The student shows a QR code or student ID, and the organiser scans it on a phone/browser to check in. |
| Environment      | During an active event at the busiest time (about 100 students arrive within 10 minutes), on campus Wi-Fi, with the system running normally. |
| Artifact         | The check-in function at the proposed API boundary and the attendance-data functions in the C++20 core; CSV/JSON records in the course implementation. |
| Response         | Find the student's registration, mark them as attended, and show a confirmation message on the organiser's screen. |
| Response measure | Across 100 check-ins in 10 minutes: 95 of 100 finish within 2 seconds, 0 check-ins are lost or counted twice, and the system handles at least 20 check-ins per minute. |

## QAS-03 · Usability · written by Seng Sarak
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

## QAS-04 · Security · written by Sok Chungseang
| Part             | Content |
|------------------|---------|
| Source           | Another student who guesses or manipulates an attendance-list URL/API request.|
| Stimulus         | An ordinary student account attempts to read a club leader's or organiser's attendee list by changing an event ID or requesting an admin endpoint.|
| Environment      | During an active event, using a student phone/browser on campus Wi-Fi; attacker signs in with a valid student-only account but has no organiser/admin privileges.|
| Artifact         | Authentication/role-based authorization at the proposed API boundary and attendance-data access functions in the C++20 core; CSV/JSON records in the course implementation.|
| Response         | Reject access without revealing another student's attendance information; record a security event without logging sensitive values. Real student IDs, names and e-mail addresses must not be included in publicly committed test data.|
| Response measure | Across 20 unauthorised access attempts covering event IDs and roles: 0 student IDs, 0 names, 0 e-mail addresses and 0 attendance records exposed; 20 of 20 requests denied and logged with an event identifier.|

## QAS-05 · Modifiability · written by Pheng Sopheak
| Part             | Content |
|------------------|---------|
| Source           | A developer in the ITC Club Hub team. |
| Stimulus         | The developer wants to add a new event type, for example a workshop with a limited number of seats. |
| Environment      | During development, before the next release, when the existing code and tests already work. |
| Artifact         | The event-management functions in the C++20 core and the proposed API boundary; CSV/JSON records in the course implementation. |
| Response         | The developer adds the new event type in the core, updates the API and the records, and runs the existing tests. |
| Response measure | Done by one developer within 4 hours, changing at most 3 source files; 0 existing tests fail; 0 changes needed in the check-in code. |

## QAS-06 · Portability · written by __
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   |                     |                |          |        |
| QAS-02   | H | M | Organisers and students who wait at the door during the busiest check-in time | Yes |
| QAS-03   |                     |                |          |        |
| QAS-04   | H | H | Students whose IDs, names, e-mails and attendance data are stored; IT staff | Yes |
| QAS-05   | M | M | The development team, who must add new event types in the future | No |
| QAS-06   |                     |                |          |        |
