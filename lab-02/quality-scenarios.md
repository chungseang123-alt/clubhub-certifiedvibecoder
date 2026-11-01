# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-30-10 · Reviewed by (Scrum Master): Sok Chungseang

## QAS-01 · Availability · written by __
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

## QAS-02 · Performance of check-in at the door · written by __
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

## QAS-03 · Usability · written by __
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

## QAS-05 · Modifiability · written by __
| Part             | Content |
|------------------|---------|
| Source           |         |
| Stimulus         |         |
| Environment      |         |
| Artifact         |         |
| Response         |         |
| Response measure |         |

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
| QAS-02   |                     |                |          |        |
| QAS-03   |                     |                |          |        |
| QAS-04   | H | H | Students whose IDs, names, e-mails and attendance data are stored; IT staff | Yes |
| QAS-05   |                     |                |          |        |
| QAS-06   |                     |                |          |        |