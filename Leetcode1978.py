import pandas as pd

def find_employees(employees: pd.DataFrame) -> pd.DataFrame:
    employees = employees[(employees['salary'] < 30000) & \
            (~employees['manager_id'].isin(employees['employee_id']) & 
            ~employees['manager_id'].isnull())]
    return employees.sort_values('employee_id')[['employee_id']]
