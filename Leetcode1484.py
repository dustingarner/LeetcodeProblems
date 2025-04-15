import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    def get_item_list(col):
        return ','.join(col.sort_values().drop_duplicates())

    activities = activities.drop_duplicates()
    item_grouping = activities.groupby('sell_date')['product'].agg([('num_sold', 'count'), ('products', get_item_list)])
    item_grouping = item_grouping.reset_index()
    return item_grouping.sort_values('sell_date')
