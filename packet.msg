packet GlobalIn {
    int inId;
    int bId;
}
packet DownloadIn {
    int inId;
    int bId;
}
packet UploadIn {
    int inId;
    int bId;
}

packet GlobalDOut {
    int inId;
    int bId;
}

packet DownloadDOut {
    int inId;
    int bId;
}
packet UploadDOut {
    int inId;
    int bId;
}

packet DownloadReduce {
	int bId;
}

packet UploadReduce {
	int bId;
}
