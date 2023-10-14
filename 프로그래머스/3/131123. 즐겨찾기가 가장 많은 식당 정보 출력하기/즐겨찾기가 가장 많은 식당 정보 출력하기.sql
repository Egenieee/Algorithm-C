# select food_type, rest_name, rest_id, favorites
# from rest_info
# group by food_type
# having favorites = max(favorites)
# order by food_type;

select food_type, rest_id, rest_name, favorites
from rest_info
where (food_type, favorites) in (
    select food_type, max(favorites)
    from rest_info
    group by food_type
)
order by food_type desc;