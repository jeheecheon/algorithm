function solution(video_len, pos, op_start, op_end, commands) {
    const convertToNum = (str) => str.split(":")
        .map(Number)
        .reduce((prev, cur, idx) => prev + cur * (idx == 0 ? 60 : 1), 0);
    
    video_len = convertToNum(video_len);
    pos = convertToNum(pos);
    op_start = convertToNum(op_start);
    op_end = convertToNum(op_end);
    
    if (pos >= op_start && pos <= op_end)
        pos = op_end;
    
    commands.forEach((e) => {
        switch (e) {
            case "next":
                pos = Math.min(pos + 10, video_len);
                break;
            case "prev":
                pos = Math.max(pos - 10, 0);
                break;
        }
        
        if (pos >= op_start && pos <= op_end)
            pos = op_end;
    });
    
    return [~~(pos / 60), ~~(pos % 60)]
        .map(String)
        .map(e => e.padStart(2, '0'))
        .join(":");
}