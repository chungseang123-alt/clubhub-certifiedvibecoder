# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-30-10 · Reviewed by (Scrum Master): Sok Chungseang

## QAS-01 · Availability · written by Seng Sarak
| Part             | Content |
|------------------|---------|
| Source           | System infrastructure |
| Stimulus         | The database or app server crashes during high user traffic. |
| Environment      | Friday 16:00, registration opens; 150 arrivals in 2 minutes attempting to register all at the same time. |
| Artifact         | ITC Club Hub core service, database connection, and API backend. |
| Response         | Automatically failover to backup database instance and restart the failed service. |
| Response measure | System recovers and resumes normal operation in <= 30 seconds; downtime per month allowed is <= 43.8 minutes. |

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
| Source           | A new student user attending a club event. |
| Stimulus         | The student attempts to register for an upcoming event using their Student ID and current academic year. |
| Environment      | Normal operation using a mobile phone browser right before registration closes. |
| Artifact         | Student registration interface. |
| Response         | Provides a simple, single-page form for students to input their information. |
| Response measure | Form completed in <= 3 steps; 100% of test users submit their student ID and current year in <= 45 seconds. |

## QAS-04 · Security · written by Sok Chungseang
| Part             | Content |
|------------------|---------|
| Source           | Another student who guesses or manipulates an attendance-list URL/API request.|
| Stimulus         | An ordinary student account attempts to read a club leader's or organiser's attendee list by changing an event ID or requesting an admin endpoint.|
| Environment      | During an active event, using a student phone/browser on campus Wi-Fi; attacker signs in with a valid student-only account but has no organiser/admin privileges.|
| Artifact         | Authentication/role-based authorization at the proposed API boundary and attendance-data access functions in the C++20 core; CSV/JSON records in the course implementation.|
| Response         | Reject access without revealing another student's attendance information; record a security event without logging sensitive values. Real student IDs, names and e-mail addresses must not be included in publicly committed test data.|
| Response measure | Across 20 unauthorised access attempts covering event IDs and roles: 0 student IDs, 0 names, 0 e-mail addresses and 0 attendance records exposed; 20 of 20 requests denied and logged with an event identifier.|

## QAS-05 · Modifiability · written by Song Panhaseth

| Part             | Content |
|------------------|---------|
| Source           | A developer maintaining or extending the ITC Club Hub application. |
| Stimulus         | The developer needs to add a new field, such as a student's phone number, to the event registration process. |
| Environment      | During normal development using C++20, CMake 3.28+, and Git, while existing event registration and check-in functions must continue to work correctly. |
| Artifact         | The C++20 registration module, student registration data structure, and CSV/JSON data storage functions. |
| Response         | Allow the developer to add the new registration field by modifying the relevant modules without rewriting the entire registration system or affecting existing check-in functionality. |
| Response measure | The new field can be added by modifying no more than 3 source files. Existing registration and check-in tests must still pass, and previously stored registration records must remain readable. |

## QAS-06 · Portability · written by Pheng Sopheak
| Part             | Content |
|------------------|---------|
| Source           | A developer or IT staff member who needs to run the ITC Club Hub application on a different computer system. |
| Stimulus         | The team needs to move the application from a Windows development laptop to a Linux (Ubuntu) server at ITC. |
| Environment      | During deployment preparation, using C++20, CMake 3.28+, and Git, while existing event registration and check-in functions already work correctly on Windows. |
| Artifact         | The C++20 core code, the CMake build files, and the CSV/JSON data storage functions. |
| Response         | Allow the developer to build and run the application on Linux using CMake, without rewriting the core registration and check-in code. |
| Response measure | The application is built and running on Linux by one person within 2 hours, changing no more than 2 source files. Existing registration and check-in tests must still pass, and previously stored CSV/JSON records must remain readable. |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   |                     |                |          |        |
| QAS-02   | H | M | Organisers and students who wait at the door during the busiest check-in time | Yes |
| QAS-03   |                     |                |          |        |
| QAS-04   | H | H | Students whose IDs, names, e-mails and attendance data are stored; IT staff | Yes |
| QAS-05   | M | M |  Developers and future maintainers of ITC Club Hub. | No |
| QAS-06   | L | M | IT staff and future maintainers who may need to move ITC Club Hub to another computer or server. | No |
