-- Last updated: 7/6/2026, 12:02:26 PM
DELETE p1
FROM Person p1
JOIN Person p2
ON p1.email = p2.email AND p1.id > p2.id;