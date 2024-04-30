from googleapiclient.discovery import build
# Range for data in sheet
RANGE_NAME = "A1:A3"

def get_values(spreadsheet_id, creds):
    service = build("sheets", "v4", credentials=creds)

    result = (
        service.spreadsheets()
        .values()
        .get(spreadsheetId=spreadsheet_id, range=RANGE_NAME)
        .execute()
    )
    data = result.get("values", [])
    output = ", ".join(sublist[0] for sublist in data)
    print(output)