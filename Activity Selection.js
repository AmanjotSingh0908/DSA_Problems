class Solution {
    activitySelection(start, end) {
        let activities = [];
        for (let i=0; i < start.length; i++) {
            activities.push({start: start[i], end:end[i]});
        }
        
        activities.sort((a,b) => a.end - b.end);
        
        let count = 1;
        let lastEndTime = activities[0].end;
        
        for(let i=1; i < activities.length; i++) {
            if(activities[i].start > lastEndTime) {
                count++;
                lastEndTime = activities[i].end;
            }
        }
        
        return count;
    }
}
