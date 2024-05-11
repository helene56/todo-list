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
    
    print(data)
    # clean data up to get the pure values/strings
    cleaned_data = [str(value).replace("['", "").replace("']", "") for value in data]
    # write the data from sheet to a txt doc
    write_to_doc("text.txt", cleaned_data)
    # output = ", ".join(sublist[0] for sublist in data)
    # print(output)

def write_to_doc(file, data):
    with open(file, 'w') as file:
        for value in data:
            file.write(f"{value}\n")