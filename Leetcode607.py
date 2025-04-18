import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    red_orders = company[company.name == 'RED'].merge(orders, on='com_id')
    return sales_person[~sales_person.sales_id.isin(red_orders.sales_id)][['name']]
