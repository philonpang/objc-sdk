//
//  AVSearchSortBuilder.m
//  paas
//
//  Created by yang chaozhong on 6/13/14.
//  Copyright (c) 2014 AVOS. All rights reserved.
//

#import "AVSearchSortBuilder.h"

@implementation AVSearchSortBuilder

+ (instancetype)newBuilder {
    AVSearchSortBuilder *sortBuilder = [[[self class] alloc] init];
    return sortBuilder;
}

- (id)init {
    self = [super init];
    _sortFields = [[NSMutableArray alloc] init];
    
    return self;
}

- (void)orderByAscending:(NSString *)key {
    [self orderByAscending:key withMode:@"avg"];
}

- (void)orderByAscending:(NSString *)key withMode:(NSString *)mode {
    [self orderByAscending:key withMode:mode andMissing:@"_last"];
}

- (void)orderByAscending:(NSString *)key withMode:(NSString *)mode andMissing:(NSString *)missing {
    [self addFiled:key inOder:@"asc" withMode:mode andMissing:missing];
}

- (void)orderByDescending:(NSString *)key {
    [self orderByDescending:key withMode:@"avg"];
}

- (void)orderByDescending:(NSString *)key withMode:(NSString *)mode {
    [self orderByDescending:key withMode:mode andMissing:@"_last"];
}

- (void)orderByDescending:(NSString *)key withMode:(NSString *)mode andMissing:(NSString *)missing {
    [self addFiled:key inOder:@"desc" withMode:mode andMissing:missing];

}

- (void)addFiled:(NSString *)key inOder:(NSString *)order withMode:(NSString *)mode andMissing:(NSString *)missing {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    if (order) {
        [dict setObject:order forKey:@"order"];
    }
    
    if (mode) {
        [dict setObject:mode forKey:@"mode"];
    }
    
    if (missing) {
        NSString *symbol = [missing hasPrefix:@"_"] ? @"" : @"_";
        [dict setObject:[NSString stringWithFormat:@"%@%@", symbol, missing] forKey:@"missing"];
    }
    
    NSDictionary *field = @{key: dict};
    [_sortFields addObject:field];
}

@end
