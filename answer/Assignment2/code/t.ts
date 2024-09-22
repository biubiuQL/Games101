let list = [
    {
        "area_code_data_list": [{ "code": "850", "name": "香港", "lang": "zh-HK" }],
        "company_code": "60",
        "tel_area_code_list": ["60", "852", "84", "1"]
    },
    {
        "area_code_data_list": [{ "code": "850", "name": "香港", "lang": "zh-HK" }],
        "company_code": "25",
        "tel_area_code_list": ["60", "90", "84", "1"]
    }
]


localStorage.setItem("info", JSON.stringify(list))
let info = localStorage.getItem("info");
if (info) {
    list = JSON.parse(info);
}
function getCompanyCode(list, tel_area_code_list_v) {
    let cell = list.find((el) => {
        let tel_area_code_list = el.tel_area_code_list
        let v = tel_area_code_list.find((el) => {
            return el == tel_area_code_list_v
        })
        if (v) {
            return true
        }
    })
    if (cell) return cell.company_code
    else return null
}

let company_code = getCompanyCode(list, "852")
console.log(company_code)