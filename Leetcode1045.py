import pandas as pd

def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    purchases = customer.drop_duplicates()
    purch_by_cust = purchases.groupby('customer_id')['product_key'].count().reset_index()
    return purch_by_cust[purch_by_cust['product_key'] == len(product)][['customer_id']]
