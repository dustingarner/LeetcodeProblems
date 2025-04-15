import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    first_activity = activity.groupby('player_id')['event_date'].min().reset_index()
    first_activity = first_activity.rename(columns={'event_date': 'first_login'})
    return first_activity[['player_id', 'first_login']]
