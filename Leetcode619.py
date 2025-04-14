import pandas as pd

def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    num_counts = my_numbers.groupby('num').value_counts().reset_index()
    singles = num_counts[num_counts['count'] == 1]['num']
    return pd.DataFrame({'num': [singles.max()]})
