// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

#import "TestInfoStore.h"


@implementation TestInfoStore

- (nonnull instancetype)initWithId:(int32_t)id
                              name:(nonnull NSString *)name
                           project:(nonnull NSString *)project
                               sex:(SexModeEnum)sex
{
    if (self = [super init]) {
        _id = id;
        _name = [name copy];
        _project = [project copy];
        _sex = sex;
    }
    return self;
}

+ (nonnull instancetype)testInfoStoreWithId:(int32_t)id
                                       name:(nonnull NSString *)name
                                    project:(nonnull NSString *)project
                                        sex:(SexModeEnum)sex
{
    return [(TestInfoStore*)[self alloc] initWithId:id
                                               name:name
                                            project:project
                                                sex:sex];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ name:%@ project:%@ sex:%@>", self.class, (void *)self, @(self.id), self.name, self.project, @(self.sex)];
}

@end
