select p.product_id,  
  ROUND((IFNULL((SUM(p.price * u.units) / SUM(u.units)),0)),2) AS average_price
FROM prices as p
left join UnitsSold as u
on p.product_id=u.product_id
AND u.purchase_date between p.start_date and p.end_date
GROUP BY product_id;

