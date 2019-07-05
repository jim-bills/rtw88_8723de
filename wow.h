/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */
/* Copyright(c) 2018-2019  Realtek Corporation
 */

#ifndef __RTW_WOW_H__
#define __RTW_WOW_H__

enum rtw_suspend_mode {
	RTW_SUSPEND_IDLE = 0x0,
	RTW_SUSPEND_LINKED = 0x01,
};

enum rtw_wake_reason {
	RTW_WOW_RSN_RX_GTK_REKEY = 0x2,
	RTW_WOW_RSN_RX_DEAUTH = 0x8,
	RTW_WOW_RSN_DISCONNECT = 0x10,
	RTW_WOW_RSN_RX_MAGIC_PKT = 0x21,
};

struct rtw_fw_media_status_iter_data {
	struct rtw_dev *rtwdev;
	u8 connect;
};

struct rtw_fw_key_type_iter_data {
	struct rtw_dev *rtwdev;
	u8 group_key_type;
	u8 pairwise_key_type;
};

static inline bool rtw_wow_supported(struct rtw_dev *rtwdev)
{
	if (!rtwdev->chip->wow_supported)
		return false;

	if (!rtwdev->wow_fw.firmware)
		return false;

	return true;
}

int rtw_wow_suspend(struct rtw_dev *rtwdev, struct cfg80211_wowlan *wowlan);
int rtw_wow_resume(struct rtw_dev *rtwdev);

#endif
