select c.id,c.movie,c.description,c.rating
from Cinema as c
where c.id%2=1 and description!="boring"
order by c.rating DESC;
