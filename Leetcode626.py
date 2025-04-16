import pandas as pd

def exchange_seats(seat: pd.DataFrame) -> pd.DataFrame:
    seat['id'] = seat['id'].map(lambda x: x if (x % 2 and x == len(seat)) else x + 1 if x % 2 else x - 1)
    return seat.sort_values('id')
