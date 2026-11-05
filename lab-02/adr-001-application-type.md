# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-30-10 · Status: Proposed | Accepted (11/04/26) · Deciders: Oeung Keangheang

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students       | Android or iPhone | Campus, home or commuting | Usually online though may encounter weak Wi-Fi/mobile data | Browse regularly | Registration or cancellation must be accurately recorded; reminders and door check-in must work smoothly |
| Organisers     | Android or iPhone | Event entrance | Wi-Fi may fail under crowd load | Bursts of intense check-in during events | Fast check-in must remain possible if Wi-Fi fails and attendance must reconcile correctly |
| Administrators | Desktop/laptop browser | ITC administrative office | Normally online | Club approvals as requests arrive and monthly activity reporting | Club approvals/rejections and campus-wide monthly reports must stay accurate and access-controlled |

## Options
A. Native Android + iOS apps + responsive admin web portal.  
B. Cross-platform mobile app for students/organisers + responsive admin web portal.   
C. Installable PWA for students/organisers, with responsive desktop layouts for administrators.  
D. Responsive web application for everyone, without installability/offline support.

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A | B | C | D |
|--------------------|-----------------|---|---|---|---|
| Cost for our team in one semester (3) | Limited time and a 5 person beginner team make implementation/maintenance cost critical. | 2 × 3 = 6 | 3 × 3 = 9| 5 × 3 = 15| 5 × 3 = 15|
| Reach (3)                             | Students use mixed Android/iOS devices; access should not depend on a specific platform.| 5 × 3 = 15| 5 × 3 = 15| 5 × 3 = 15| 5 × 3 = 15|
| Offline check-in at the door (3)      | Entrance connectivity can fail during an event, when check-in is most important.| 5 × 3 = 15| 4 × 3 = 12| 4 × 3 = 12| 1 × 3 = 3|
| Reminders (2)                         | Reminders reduce no-shows, but e-mail can provide a fallback when push is limited.| 5 × 2 = 10| 5 × 2 = 10| 3 × 2 = 6| 2 x 2 = 4|
| Desktop approvals and monthly reports for administrators (2)             |Only 2–3 users and low volume (approvals as they arrive, one report a month), but errors here affect campus-wide records. |5 × 2 = 10 | 5 × 2 = 10| 5 × 2 = 10| 5 × 2 = 10|
| **Total**                             | max is 65| 6 + 15 + 15 + 10 + 10 = 56 | 9 + 15 + 12 + 10 + 10 = 56 | 15 + 15 + 12 + 6 + 10 = 58 | 15 + 15 + 3 + 4 + 10 = 47 |

Deal-breaker check: 

Deal-breakers: (1) check-in must work without Wi-Fi; (2) approvals and reports must be accessible only to administrators; (3) students must still get reminders if push is unavailable.

-D fails (1). An online-only web app can’t record check-ins when the door Wi-Fi drops, so it is out regardless of its score.
-C passes (1) with a condition. A service worker caches the check-in screen, and attendee data is pre-loaded on the organiser’s phone before the event. Check-ins are queued locally and synced when connectivity returns, with a unique check-in ID so repeated syncs don’t create duplicates. The change we add is that the organiser must open the PWA online once before the event to cache the list.
-C passes (2). Role checks happen on the server, not just in the UI, so a student can’t reach admin routes.
-C passes (3) with a fallback. iPhone push only works after the PWA is installed to the Home Screen, so e-mail reminders remain the fallback for everyone.

Result: C survives all three, with the offline queue and e-mail fallback added.

## Decision
One responsive PWA shared across the three primary user groups, with an appropriately permissioned club-leader view. Provide a phone-friendly student experience, an installable organiser check-in view with locally queued offline actions, and desktop-optimised administrative club approval and monthly reporting. Include an email reminder fallback and verify the offline workflow before accepting the design as feasible.
## Consequences
+ A shared codebase reduces the amount of UI work and maintenance for the team
+ Students can visit by URL; organisers can install the PWA; administrators can work in desktop browsers
+ A cached check-in interface can continue recording local actions during brief connectivity loss after advance setup
- Offline queues, conflict resolution and secure local attendee data storage increase implementation and testing complexity
- Push-notification behaviour and PWA installation vary across browsers and operating systems; e-mail fallback is needed
- Cached attendee data on lost phones introduces privacy risk; minimise stored fields, expire data and require organiser authentication
## Rejected options
- Native Android + iOS + web: best device integration, but two native mobile implementations plus an admin portal are expensive 
- Cross-platform mobile + web: strong mobile experience, but still requires a separate admin web experience and more deployment work than one PWA
- Responsive web only: easiest initial access, but ordinary online-only pages do not meet offline door check-in requirements.
## How the front ends reach the C++ core
Club Hub’s PWA would connect securely to a server that checks users’ identities and permissions before using the C++20 core. The CLI uses the core directly and stores data in CSV/JSON files. The UI, API and database will come later. Lessons from past failures guide input checks, activity logs, safe file saving and check-in/sync that avoids duplicates when repeated.
