import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    director_count = actor_director.groupby(['actor_id', 'director_id'])['timestamp'].count().reset_index(name='cooperation_count')
    return director_count[director_count.cooperation_count >= 3][['actor_id', 'director_id']]
