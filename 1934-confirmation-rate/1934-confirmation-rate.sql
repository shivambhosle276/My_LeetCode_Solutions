SELECT s.user_id, round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate
FROM Signups as s
LEFT JOIN Confirmations as c on s.user_id = c.user_id
group by user_id;
