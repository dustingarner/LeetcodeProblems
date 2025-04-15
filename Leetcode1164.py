import pandas as pd

def price_at_given_date(products: pd.DataFrame) -> pd.DataFrame:
    before_date = products[products['change_date'] <= pd.to_datetime('2019-08-16')]
    max_dates = before_date.groupby('product_id')['change_date'].max().reset_index()
    prices = max_dates.merge(before_date, on=['product_id', 'change_date']).rename(columns={'new_price': 'price'})

    later_changed = products.product_id[~products.product_id.isin(before_date.product_id)]
    other_prices = pd.DataFrame({'product_id': pd.unique(later_changed), 'price': 10})

    return pd.concat([prices, other_prices])[['product_id', 'price']]
